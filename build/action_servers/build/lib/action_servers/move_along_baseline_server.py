import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node
from action_interfaces.action import MoveAlongBaseline 
from kr_msgs.srv import GetRobotPose
from kr_msgs.msg import JogLinear

class MoveAlongBaselineServer(Node):

    def __init__(self):
        super().__init__('move_along_baseline_server')
        
        self._action_server = ActionServer(
            self,
            MoveAlongBaseline,
            'move_along_baseline',
            self.execute_callback
        )

        self.pose_client = self.create_client(GetRobotPose, '/kr/robot/get_robot_pose')
        self.jog_publisher = self.create_publisher(JogLinear, '/kr/motion/jog_linear', 10)

    def execute_callback(self, goal_handle):
        self.get_logger().info(f'Ziel erhalten: Strecke in x-Richtung: {goal_handle.request.baseline} mm')

        while not self.pose_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn('Warte auf den Service GetRobotPose...')
        self.get_logger().info(f"Service Kassow GetRobotPose verfügbar!")

        baseline = goal_handle.request.baseline
        request = GetRobotPose.Request()

        future = self.pose_client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        response = future.result()
        if not response.success:
            goal_handle.abort()
            return MoveAlongBaseline.Result(success=False, message="Fehler beim Abrufen der aktuellen Pose")

        # Aktuelle x-Position des Roboters und Ziel berechnen
        start_x = response.pos[0]
        target_x = start_x + baseline
        self.get_logger().info(f'Startposition: {start_x} mm, Zielposition: {target_x} mm')

        # Toleranz für Zielerreichung
        position_tolerance = 1.0  # in mm

        # Schleife, um Roboter zu bewegen, bis Ziel erreicht
        while rclpy.ok():
            # Aktuelle Pose
            future = self.pose_client.call_async(request)
            rclpy.spin_until_future_complete(self, future)
            response = future.result()
            if not response.success:
                self.get_logger().warn('Fehler beim Abrufen der aktuellen Pose')
                continue

            # Aktuelle x-Position
            current_x = response.pos[0]

            # Feedback an Client
            feedback = MoveAlongBaseline.Feedback()
            feedback.current_x = current_x
            goal_handle.publish_feedback(feedback)

            # Prüfen, ob Ziel erreicht
            if abs(target_x - current_x) <= position_tolerance:
                self.get_logger().info('Zielposition erreicht.')
                goal_handle.succeed()
                return MoveAlongBaseline.Result(success=True, message="Zielposition erreicht.")

            # Bewegung Roboter in x-Richtung
            msg = JogLinear()
            msg.vel = [20.0, 0.0, 0.0]
            msg.rot = [0.0, 0.0, 0.0]
            self.jog_publisher.publish(msg)

            # Verzögerung (0.05 Sekunden)
            # rclpy.sleep(0.05)

def main(args=None):
    rclpy.init(args=args)
    server = MoveAlongBaselineServer()
    rclpy.spin(server)
    rclpy.shutdown()

if __name__ == '__main__':
    main()

