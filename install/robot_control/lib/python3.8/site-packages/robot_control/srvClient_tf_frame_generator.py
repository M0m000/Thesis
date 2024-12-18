import rclpy
from rclpy.node import Node
from action_interfaces.srv import GenerateFrame

def main(args=None):
    rclpy.init(args=args)

    node = Node('tf_frame_generator_client')
    client = node.create_client(GenerateFrame, 'generate_frame')

    # Wait for the service to be available
    if not client.wait_for_service(timeout_sec=10.0):
        node.get_logger().error('Service "generate_frame" not available.')
        rclpy.shutdown()
        return

    # Create the request
    request = GenerateFrame.Request()
    request.frame_new = 'frame_new'
    request.frame_ref = 'tcp'
    request.translation = [-10.0, -20.0, -30.0]  # Example translation
    request.rotation_rpy = [0.1, 0.2, 0.3]  # Example rotation (roll, pitch, yaw)

    # Call the service
    future = client.call_async(request)

    def callback(future):
        try:
            response = future.result()
            if response.success:
                node.get_logger().info(f'Success: {response.message}')
            else:
                node.get_logger().error(f'Failed: {response.message}')
        except Exception as e:
            node.get_logger().error(f'Service call failed: {e}')
        finally:
            rclpy.shutdown()

    future.add_done_callback(callback)

    rclpy.spin(node)

if __name__ == '__main__':
    main()
