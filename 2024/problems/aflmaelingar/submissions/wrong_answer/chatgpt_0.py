#!/usr/bin/python3
def read_input():
    K, q = map(int, input().split())
    return K, q

def make_query(percentages):
    print(' '.join(map(str, percentages)), flush=True)
    return int(input())

def solve(K, q, n=300):
    # Initialize base powers list
    base_powers = [0] * n
    
    for i in range(n):
        # Set all generators to 0% except for the current one
        percentages = [0] * n
        percentages[i] = 100  # Set the current generator to 100%
        
        # Make the query to get the output
        output = make_query(percentages)
        
        # The last two digits of the output give the base power of the current generator
        base_powers[i] = output % 100
    
    # Print the base powers of all generators
    print(' '.join(map(str, base_powers)), flush=True)

if __name__ == "__main__":
    K, q = read_input()
    solve(K, q)

