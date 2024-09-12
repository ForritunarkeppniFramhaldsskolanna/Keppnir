#!/usr/bin/python3
def remaining_curtains(n, m):
    return n - m

if __name__ == "__main__":
    # Read the total number of windows initially covered by curtains
    n = int(input())
    # Read the total number of window curtains that have been drawn open
    m = int(input())
    
    # Calculate the number of remaining curtains
    remaining = remaining_curtains(n, m)
    
    # Print the result
    print(remaining)
