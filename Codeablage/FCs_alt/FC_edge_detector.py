class EdgeDetector:
    def __init__(self):
        self.edge_detection_help_variable = None  # Hilfsvariable zum Speichern des letzten Zustands von var

    def detect_edge(self, var=None):
        rising_edge = False
        falling_edge = False

        if var is not None:
            if self.edge_detection_help_variable is not None:
                if self.edge_detection_help_variable == False and var == True:
                    rising_edge = True
                    falling_edge = False
                elif self.edge_detection_help_variable == True and var == False:
                    falling_edge = True
                    rising_edge = False
                else:
                    rising_edge = False
                    falling_edge = False
            else:
                rising_edge = False
                falling_edge = False

            self.edge_detection_help_variable = var
        return rising_edge, falling_edge