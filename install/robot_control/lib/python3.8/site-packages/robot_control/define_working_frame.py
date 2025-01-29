import rclpy
from rclpy.node import Node

class DefineWorkingFrame(Node):
    def __init__(self):
        super().__init__('define_working_frame')
        self.stations = ['Init', 'REF', 'POS1', 'POS2']
        self.current_station = 0
        self.get_logger().info(f'Start at {self.stations[self.current_station]}')
        self.run_sequence()

    def run_sequence(self):
        while self.current_station < (len(self.stations)-1):
            if self.stations[self.current_station] == 'Init':
                self.Init()
            elif self.stations[self.current_station] == 'REF':
                self.save_REF()
            elif self.stations[self.current_station] == 'POS1':
                self.save_POS1()            
            
            user_input = input()

            if user_input.strip().lower() == 'done':
                self.current_station += 1
            else:
                self.get_logger().info('Ungültige Eingabe. Bitte "done" eingeben.')
        self.save_POS2_and_calculate_transform()
        self.get_logger().info("Done!")

    def Init(self):
        self.get_logger().info("Move Robot Needle to <REF>... then type <done>")
        
    def save_REF(self):
        # speichere REF System Punkt in Bezug auf WORLD
        self.get_logger().info("Move Robot Needle to <POS1>... then type <done>")
        
    def save_POS1(self):
        # speichere POS1 System Punkt in Bezug auf WORLD
        self.get_logger().info("Move Robot Needle to <POS2>... then type <done>")
        
    def save_POS2_and_calculate_transform(self):
        # speichere POS2 System Punkt in Bezug auf WORLD
        self.get_logger().info("Calculating Transformation between WORLD and REF...")
        # berechne Vektoren wie in Onenote beschrieben
        # Erstelle Drehmatrix im Punkt REF
        # Erstelle Transformationsmatrix von REF in Bezug auf WORLD
        self.get_logger().info("Transformation between WORLD and REF saved in tf2 as <WORK>")
        
        

def main(args=None):
    rclpy.init(args=args)
    node = DefineWorkingFrame()
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()