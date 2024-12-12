import rclpy
from rclpy.node import Node
from py_trees import BehaviourTree, composites, behaviours, common
from action_msgs.msg import GoalStatus
from rclpy.action import ActionClient
from example_interfaces.srv import Trigger
from action_interfaces.action import MoveTcpAlongAxis, TakePicture

class WaitForKey(Node):
    '''
    Knoten, der auf zwei Services hört. Der Service start_robot_process startet den Behaviour Tree 
    und der Service "stop_robot_process" stoppt den Tree. Das Stoppen des Trees ist jederzeit möglich.
    Wenn der Tree gestoppt wird, fährt der Roboter wieder in seine Init-Position
    '''

    def __init__(self):
        super().__init__('wait_for_key')

        # Services für Start bzw. Stop
        self.service = self.create_service(Trigger, 'start_robot_process', self.handle_key_press)
        self.stop_service = self.create_service(Trigger, 'stop_robot_process', self.handle_stop_key_press)

        # Flags gestartet/gestoppt
        self.key_pressed = False
        self.stop_pressed = False

    def handle_key_press(self, request, response):
        # wenn Start-Service aufgerufen
        self.get_logger().info("Key press detected. Starting process.")

        # Flag Start setzen
        self.key_pressed = True

        # Antwort des Service - success True und message
        response.success = True
        response.message = "Process started."
        return response

    def handle_stop_key_press(self, request, response):
        self.get_logger().info("Stop key press detected. Stopping process.")

        # Flag Stop setzen
        self.stop_pressed = True

        # Antwort des Service success True und message
        response.success = True
        response.message = "Process stopping."
        return response

class MoveTcpAlongAxisActionClient(Node):
    '''
    Knoten für den Action Client zum Aufruf der Action MoveTcpAlongAxis
    '''

    def __init__(self):
        super().__init__('move_tcp_along_axis_action_client')
        self._action_client = ActionClient(self, MoveTcpAlongAxis, 'move_tcp_along_axis')

    def send_goal(self, baseline, movement_frame, movement_axis, speed):
        # sende Zielanfrage mit Übergabeparametern
        goal_msg = MoveTcpAlongAxis.Goal()
        goal_msg.baseline = baseline
        goal_msg.movement_frame = movement_frame
        goal_msg.movement_axis = movement_axis
        goal_msg.speed_in_mm_per_s = speed

        # Timeout wenn Action-Server nicht verfügbar
        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().info("Server is not available after waiting.")
            return None

        future = self._action_client.send_goal_async(goal_msg)
        return future

class TakePictureActionClient(Node):
    '''
    Knoten für Action Client zum Aufruf von Action XXXX
    '''
    def __init__(self):
        super().__init__('take_picture_action_client')
        self._action_client = ActionClient(self, TakePicture, 'take_picture')

    def send_goal(self):
        # sende Zielanfrage um Bild aufzunehmen
        goal_msg = TakePicture.Goal()

        # Timeout wenn Action-Server nicht verfügbar
        if not self._action_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().info("Server is not available after waiting.")
            return None

        future = self._action_client.send_goal_async(goal_msg)
        return future

class MoveToInitPosBehaviour(behaviours.Behaviour):
    '''
    Knoten: Startet wenn der Behaviour Tree beendet bzw. abgebrochen wurde.
    '''
    def __init__(self, move_client):
        super().__init__(name="Move to Init Pos")
        self.move_client = move_client

    def update(self):
        self.move_client.get_logger().info("Moving robot to initial position...")
        move_future = self.move_client.send_goal(0, "base_link", "x", 50.0)  # Example parameters

        if move_future is None or not move_future.result().result.success:
            self.move_client.get_logger().error("Failed to move robot to initial position.")
            return common.Status.FAILURE

        self.move_client.get_logger().info("Robot successfully moved to initial position.")
        return common.Status.SUCCESS

class MoveAndCaptureBehaviour(behaviours.Behaviour):
    '''
    Knoten für Scan der Hakenleiste.
    '''
    def __init__(self, move_client, picture_client, baseline, axis, frame, speed, stop_event):
        super().__init__(name="Move and Capture")
        self.move_client = move_client
        self.picture_client = picture_client
        self.baseline = baseline
        self.axis = axis
        self.frame = frame
        self.speed = speed
        self.remaining_distance = baseline
        self.stop_event = stop_event

    def update(self):
        '''
        Update-Methode für Behaviour Tree
        '''
        # beende Tree, wenn Abbruch-Service gecallt wurde
        if self.stop_event:
            return common.Status.FAILURE

        # beende Tree, wenn Leiste vollständig gescannt
        if self.remaining_distance <= 0:
            return common.Status.SUCCESS
        

        # Aufruf des MoveTcpAlongAxis Action Servers mit Übergabeparemtern
        self.move_client.get_logger().info(f"Moving {self.axis} axis by {self.baseline} mm...")
        move_future = self.move_client.send_goal(self.baseline, self.frame, self.axis, self.speed)

        if move_future is None or not move_future.result().result.success:
            self.move_client.get_logger().error("Failed to move robot.")
            return common.Status.FAILURE
        
        # Verbleibende Distanz aktualisieren
        self.remaining_distance -= self.baseline


        # Action Aufruf - nehme Bild auf
        self.picture_client.get_logger().info("Capturing image...")
        picture_future = self.picture_client.send_goal()

        if picture_future is None or not picture_future.result().result.success:
            self.picture_client.get_logger().error("Failed to capture image.")
            return common.Status.FAILURE
        
        # wenn beides geklappt hat, Tree still RUNNING
        return common.Status.RUNNING

class WaitForKeyBehaviour(behaviours.Behaviour):
    '''
    Baumknoten - Warte auf den Tastendruck für das Starten bzw. Stoppen des Trees
    '''
    def __init__(self, key_node):
        super().__init__(name="Wait for Key")
        self.key_node = key_node

    def update(self):
        if self.key_node.key_pressed:
            return common.Status.SUCCESS
        return common.Status.RUNNING

def main(args=None):
    rclpy.init(args=args)

    wait_node = WaitForKey()                            # Knoten für Start/Abbruch des Trees
    move_client = MoveTcpAlongAxisActionClient()        # Knoten für Action Client - Verfahren des Roboters
    picture_client = TakePictureActionClient()          # Knoten für Action Client - Aufnehmen der Bilder


    ''' 
    Anlegen des Behaviour Tree nach folgender Struktur:

        Root Selector
        ├── Stop Sequence
        │   ├── Check Stop
        │   └── Move to Init Pos
        └── Main Sequence
            ├── Wait for Key
            └── Move and Capture

            
        Root Selector
            - wählt zwischen alternativen Pfaden
            - überprüft alle Kinder von oben nach unten
                - stoppt bei dem ersten Kind, welches True ist
                - d.h. es wird immer zuerst überprüft ob GESTOPPT wurde -> Reset-Aktiv
                    - falls ja -> führe Check Stop aus (von py_trees) und dann Move to Init Pos (Roboter fährt in Init-Pose)
                - falls nicht gestoppt -> Beginn des Baums

        Stop Sequence / Main Sequence
            - Knoten versuchen, ihre Kinder in Reihe auszuführen
            - sobald ein Kind fehlschläft, schlägt die komplette Sequence fehl
        
        Check Stop
            - überprüft, ob Stopp-Event aktiviert
        
        Move to Init Pos
            - Roboter wird zu Init-Pose bewegt, wenn Stopp-Event aktiviert wurde

        Wait for Key
            - wartet auf Start-Trigger, um den Tree zu starten
        
        Move and Capture
            - eigentliche Funktion
            - Verfahren des TCP um Baseline entlang einer Achse
            - Aufnahme der Bilder -> Detektion der Haken (außerhalb des BTree)
        
    '''

    root = composites.Selector(name="Root Selector")
    stop_sequence = composites.Sequence(name="Stop Sequence")
    stop_check = behaviours.CheckBlackboardVariableValue(name="Check Stop", variable_name="stop", expected_value=True)
    move_to_init = MoveToInitPosBehaviour(move_client=move_client)
    stop_sequence.add_children([stop_check, move_to_init])

    main_sequence = composites.Sequence(name="Main Sequence")
    key_check = WaitForKeyBehaviour(key_node=wait_node)
    move_and_capture = MoveAndCaptureBehaviour(
        move_client=move_client,
        picture_client=picture_client,
        baseline=100,  # Set desired distance
        axis="x",
        frame="base_link",
        speed=50.0,  # Set desired speed
        stop_event=wait_node.stop_pressed
    )
    main_sequence.add_children([key_check, move_and_capture])

    root.add_children([stop_sequence, main_sequence])

    behaviour_tree = BehaviourTree(root)

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(wait_node)
    executor.add_node(move_client)
    executor.add_node(picture_client)

    # Start the behaviour tree ticking without using threading
    while rclpy.ok():
        behaviour_tree.tick_tock()
        executor.spin_once()  # Call spin_once to process the node callbacks

    rclpy.shutdown()

if __name__ == '__main__':
    main()


