#!/usr/bin/python3
# Function to calculate remaining curtains
def remaining_curtains(total_windows, opened_windows):
    """
    This function calculates the number of windows with curtains remaining closed.

    Args:
        total_windows: The total number of windows initially covered by curtains.
        opened_windows: The total number of window curtains that have been drawn open.

    Returns:
        The number of windows covered by curtains.
    """

    # Calculate the number of windows with curtains remaining closed
    closed_windows = total_windows - opened_windows

    return closed_windows


# Example usage
total_windows = int(input())
opened_windows = int(input())

# Call the function to get the number of remaining closed curtains
closed_curtains = remaining_curtains(total_windows, opened_windows)

# Print the result
print(closed_curtains)
