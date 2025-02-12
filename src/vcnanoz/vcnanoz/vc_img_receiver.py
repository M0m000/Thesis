import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from std_msgs.msg import Int32
from std_msgs.msg import Header
import socket
import struct
import time
from itertools import chain
import numpy as np
import cv2
from cv_bridge import CvBridge


class VCImageReceiver(Node):
    def __init__(self):
        super().__init__('vc_img_receiver')
        self.get_logger().info('Starting ROS2 Connection to VCnanoZ')

        self.img = None
        self.img_tensor = None

        # Socket
        self.sock = None
        self.sock_to = None

        # FPS
        self.last_frame_time = None
        self.fps = 0.0

        # Timer für Einlesen der Bilder
        self.timer_period = 0.0001
        self.timer = self.create_timer(self.timer_period, self.receive_img)

        # Parameterübergabe
        self.declare_parameter('ipv4', '192.168.3.15')
        self.ipv4 = self.get_parameter('ipv4').get_parameter_value().string_value
        self.declare_parameter('port', 2002)
        self.port = self.get_parameter('port').get_parameter_value().integer_value
        self.declare_parameter('img_width', 2048)
        self.dx = self.get_parameter('img_width').get_parameter_value().integer_value
        self.declare_parameter('img_height', 1536)
        self.dy = self.get_parameter('img_height').get_parameter_value().integer_value
        self.declare_parameter('rgb_stream', False)
        self.rgb_stream = self.get_parameter('rgb_stream').get_parameter_value().bool_value
        self.declare_parameter('show_img', True)
        self.show_img = self.get_parameter('show_img').get_parameter_value().bool_value
        self.declare_parameter('take_pictures', True)
        self.take_pictures = self.get_parameter('take_pictures').get_parameter_value().bool_value

        # Bild
        self.x0 = int((2048 - self.dx)/2)
        self.y0 = int((1536 - self.dy)/2)
        self.incrx = 1
        self.incry = 1

        # Bildspeicherpfad
        self.declare_parameter('save_path', '/home/mo/Thesis/vc_imgs')
        self.save_path = self.get_parameter('save_path').get_parameter_value().string_value        

        # Bridge für Publisher
        self.bridge = CvBridge()

        # ROS2 Publisher für das Bild
        self.image_publisher = self.create_publisher(Image, 'vcnanoz/image_raw', 10)
        self.get_logger().info(f'IPv4: {self.ipv4} - Port: {self.port}')
        self.image_width_publisher = self.create_publisher(Int32, 'vcnanoz/image_raw/width', 10)
        self.image_height_publisher = self.create_publisher(Int32, 'vcnanoz/image_raw/height', 10)
        
        # verbinden
        self.connect()



    def publish_image(self):
        if self.img_tensor is not None:
            ros_image = self.bridge.cv2_to_imgmsg(self.img_tensor, encoding='passthrough')

            ros_image.header = Header()
            ros_image.header.stamp = self.get_clock().now().to_msg()
            ros_image.header.frame_id = 'vc_nano_z'
            self.image_publisher.publish(ros_image)

            width = Int32()
            width.data = int(self.dx)
            self.image_width_publisher.publish(width)

            height = Int32()
            height.data = int(self.dy)
            self.image_height_publisher.publish(height)



    def receive_img(self):
        if None == self.sock:
            return False

        # FPS
        current_time = time.time()
        if self.last_frame_time is not None:
            frame_time = current_time - self.last_frame_time
            self.fps = 1.0 / frame_time
        self.last_frame_time = current_time
        self.get_logger().info(f"Streaming {self.fps:.2f} fps")

        hdr_req = struct.pack("IIIIII", self.x0, self.y0, self.dx, self.dy, self.incrx, self.incry)

        try:
            self.sock.sendall(hdr_req)
        except Exception:
            raise

        data = bytearray()

        while len(data) < 28:
            try:
                data += self.sock.recv(28 - len(data))
            except Exception:
                raise

        hdr_resp = struct.unpack_from("IIIIIII", bytes(data))
        img_bytes = hdr_resp[0] - 28
        (img_x0, img_y0, img_dx, img_dy, img_incrx, img_incry) = hdr_resp[1:7]

        if img_bytes < 0:
            raise

        img_data = bytearray(img_bytes)
        mv_img_data = memoryview(img_data)
        len_img_data = 0
        while len_img_data < img_bytes:
            bytesRead = self.sock.recv_into(mv_img_data, img_bytes - len_img_data)
            mv_img_data = mv_img_data[bytesRead:]
            len_img_data += bytesRead

        self.img = dict(x0=int(img_x0), y0=int(img_y0), dx=int(img_dx), dy=int(img_dy), incrx=img_incrx, incry=img_incry, data=img_data)

        self.create_img_tensor()

        # Bild veröffentlichen, wenn es vorhanden ist
        self.publish_image()

        if self.show_img or self.take_pictures:
            self.visualize()



    def visualize(self):
        if self.img_tensor is not None and self.show_img == True:
            cv2.imshow("Cam Img", self.img_tensor)

            key = cv2.waitKey(1) & 0xFF
            if key == ord('q'):
                self.get_logger().info("Window closed")
                rclpy.shutdown()
            elif key == ord('z') and self.take_pictures:
                self.save_image()



    def save_image(self):
        if self.img_tensor is not None:
            timestamp = int(time.time())
            filename = f"{self.save_path}/image_{timestamp}.png"
            cv2.imwrite(filename, self.img_tensor)
            self.get_logger().info(f"Image saved: {filename}")



    def create_img_tensor(self):
        if self.img is None:
            print("No Image available to save!")
            self.img_tensor = None

        dx = int(self.img['dx']) / int(self.img['incrx'])
        dy = int(self.img['dy']) / int(self.img['incry'])
        pitch = dx

        mv_img_data = memoryview(self.img['data'])

        if self.rgb_stream:
            dy //= 3
            img_data_packed = bytearray(chain.from_iterable(zip(mv_img_data[int(2 * pitch * dy):], mv_img_data[int(1 * pitch * dy):], mv_img_data[int(0 * pitch * dy):])))
        else:
            dy //= 1
            img_data_packed = bytearray(chain.from_iterable(zip(mv_img_data[int(0 * pitch * dy):], mv_img_data[int(0 * pitch * dy):], mv_img_data[int(0 * pitch * dy):])))

        img_array = np.frombuffer(img_data_packed, dtype=np.uint8)
        img_array = img_array.reshape((int(dy), int(dx), 3))

        if img_array is not None:
            self.img_tensor = img_array



    def connect(self):
        if((None != self.sock) and (self.ipv4 == self.sock_to[0]) and (self.port == self.sock_to[1])):
            return True

        if(None != self.sock):
            self.disconnect()

        self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.sock_to = (self.ipv4, self.port)

        print('connecting to %s port %s' % self.sock_to)

        try:
            self.sock.settimeout(0.75)
            self.sock.connect(self.sock_to)
            self.sock.settimeout(None)
        except Exception:
            self.sock.settimeout(None)
            raise

        self.img_nr = 0
        return True



    def disconnect(self):
        if(None != self.sock):
            print('disconnecting from %s port %s' % self.sock_to)
            self.sock.close()
        self.sock = None
        self.sock_to = None



def main(args=None):
    rclpy.init(args=args)
    node = VCImageReceiver()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

