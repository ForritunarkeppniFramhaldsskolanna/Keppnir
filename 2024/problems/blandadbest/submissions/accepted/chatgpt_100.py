#!/usr/bin/python3

def get_meat_choice():
    # Read the number of meat types offered today
    n = int(input().strip())
    # Initialize an empty list to store the meat types
    meats = []
    # Read each meat type and add it to the list
    for _ in range(n):
        meat_type = input().strip()
        meats.append(meat_type)
    
    # Determine Níels' meat choice based on the options
    if n == 2:
        return "blandad best"
    elif meats[0] == "nautakjot":
        return "nautakjot"
    else:
        return "kjuklingur"

# Execute the function and print the result
if __name__ == "__main__":
    print(get_meat_choice())
