import py_trees

# Custom Condition Node
class CheckCondition(py_trees.behaviour.Behaviour):
    def __init__(self, name, variable_name, expected_value):
        super(CheckCondition, self).__init__(name)
        self.variable_name = variable_name
        self.expected_value = expected_value

    def update(self):
        blackboard = py_trees.blackboard.Blackboard()
        value = blackboard.get(self.variable_name)
        if value == self.expected_value:
            return py_trees.common.Status.SUCCESS
        else:
            return py_trees.common.Status.FAILURE

# Function to create the behavior tree
def create_simple_tree():
    # Root node (Sequence)
    root = py_trees.composites.Sequence(name="Root")

    # First task: Check a condition
    check_condition = CheckCondition(
        name="Check Condition",
        variable_name="example_variable",
        expected_value=True
    )

    # Second task: Execute an action
    perform_action = py_trees.behaviours.Success(name="Perform Action")

    # Add the children to the root
    root.add_children([check_condition, perform_action])

    return root

# Entry point for running and visualizing the tree
def main():
    # Create the tree
    root = create_simple_tree()

    # Generate HTML visualization of the tree
    html_content = "<html><head><title>Behavior Tree</title></head><body>"
    html_content += py_trees.display.xhtml_tree(root, show_status=True)
    html_content += "</body></html>"

    # Write the HTML to a file
    with open("behavior_tree.html", "w") as file:
        file.write(html_content)

    print("Behavior tree visualization saved to 'behavior_tree.html'. Open this file in a browser to view it.")

    # Set up blackboard for the tree
    blackboard = py_trees.blackboard.Blackboard()
    blackboard.set("example_variable", True)  # Set the variable to satisfy the condition

    # Run the tree
    behaviour_tree = py_trees.trees.BehaviourTree(root)
    behaviour_tree.tick_tock(
        period_ms=1000,  # Tick every second
        number_of_iterations=3  # Limit iterations for demonstration
    )

if __name__ == "__main__":
    main()
