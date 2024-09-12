#!/usr/bin/python3
def solve_staff_assignment(n, names):
    # The mantra consists of 12 words
    mantra_length = 12
    # Calculate the starting position for the non-relative to ensure they are chosen
    non_relative_position = (mantra_length - 1) % n
    # Rearrange the names so that the non-relative ends up at the calculated position after the mantra
    ordered_names = names[1:]  # Exclude the non-relative initially
    # Insert the non-relative at the calculated position
    ordered_names.insert(non_relative_position, names[0])
    return ordered_names

def main():
    # Read the number of staff members
    n = int(input())
    # Read the names, assuming the first name is the non-relative
    names = [input().strip() for _ in range(n)]
    # Solve the assignment problem
    ordered_names = solve_staff_assignment(n, names)
    # Print the names in the order that ensures the non-relative is selected
    for name in ordered_names:
        print(name)

if __name__ == "__main__":
    main()

