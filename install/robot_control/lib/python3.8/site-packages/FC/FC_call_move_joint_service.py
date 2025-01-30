import rclpy
from rclpy.node import Node
from kr_msgs.srv import MoveJoint
from time import time

def call_move_joint_service(node: Node, pos, rot, ref, ttype, tvalue, bpoint, btype, bvalue, sync, chaining):
    client = node.create_client(MoveJoint, '/kr/motion/move_joint')
    
    # Warte, bis der Service verfügbar ist
    while not client.wait_for_service(timeout_sec=1.0):
        node.get_logger().info('Service not available, waiting again...')
    node.get_logger().info('Service MoveJoint availabel, make service call...')
    
    # Erstelle Service Request
    request = MoveJoint.Request()
    request.pos = pos
    request.rot = rot
    request.ref = ref
    request.ttype = ttype
    request.tvalue = tvalue
    request.bpoint = bpoint
    request.btype = btype
    request.bvalue = bvalue
    request.sync = sync
    request.chaining = chaining

    # Sende Service-Request und warte auf Antwort
    start_time = time()
    while True:
        future = client.call_async(request)
        rclpy.spin_until_future_complete(node, future)
        
        if future.result() is not None:
            if future.result().success:
                node.get_logger().info("Movement completed successfully")
                return True
            else:
                node.get_logger().warn("Movement failed!")
                return False
        elif time() - start_time > 10:  # Timeout nach 10 Sekunden
            node.get_logger().warn("Service call timed out!")
            return False
