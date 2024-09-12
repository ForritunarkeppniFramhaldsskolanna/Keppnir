#!/usr/bin/python3
def calculate_optimal_position(n, m, Ka, Kb, Ki):
    optimal_position = 1  # Ensure optimal_position is initialized at the start
    
    # Calculate the effect of the reversal at the destination
    if Kb < n:
        optimal_position = n - ((n - 1) // Kb) * Kb

    # Reverse the process through each connecting flight
    for cart_size in reversed(Ki):
        if cart_size < n:  # Correct condition to compare with total bags, not optimal_position
            cycle_length = n // cart_size if n % cart_size == 0 else n // cart_size + 1
            if optimal_position <= (n % cart_size) or (n % cart_size) == 0:
                optimal_position = (optimal_position - 1) % cart_size + 1
            else:
                optimal_position = (optimal_position - 1) % cart_size + 1 + (cycle_length - 1) * cart_size
    
    # Finally, reverse the process at the departure
    if Ka < n:
        cycle_length = n // Ka if n % Ka == 0 else n // Ka + 1
        if optimal_position <= (n % Ka) or (n % Ka) == 0:
            optimal_position = (optimal_position - 1) % Ka + 1
        else:
            optimal_position = (optimal_position - 1) % Ka + 1 + (cycle_length - 1) * Ka

    return optimal_position


def main():
    # Reading the first line of input for n and m
    n, m = map(int, input().split())

    # Reading the second line for Ka and Kb
    Ka, Kb = map(int, input().split())

    # Initializing Ki as an empty list if m == 0
    Ki = []

    # If m != 0, reading the next line for Ki
    if m != 0:
        Ki = list(map(int, input().split()))

    # Calculating the optimal check-in position
    optimal_position = calculate_optimal_position(n, m, Ka, Kb, Ki)

    # Printing the result to stdout
    print(optimal_position)

if __name__ == "__main__":
    main()

