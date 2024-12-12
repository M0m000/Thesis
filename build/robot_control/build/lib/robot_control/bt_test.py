import py_trees

# Function to create the behavior tree
def create_simple_tree():
    # Root node (Sequence)
    root = py_trees.composites.Sequence(name="Root")

    # First task: Check a condition
    check_condition = py_trees.behaviours.CheckBlackboardVariableValue(
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

    # Display the tree in the console
    py_trees.display.print_ascii_tree(root)

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
