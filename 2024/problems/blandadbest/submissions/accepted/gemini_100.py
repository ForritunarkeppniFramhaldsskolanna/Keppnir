#!/usr/bin/python3

def get_niels_meat(meat_types):
    """
    Determines the type of meat Níels got on his kebab.

    Args:
        meat_types: A list of strings representing the meat types offered by KFFÍ.

    Returns:
        A string indicating the type of meat Níels got:
            - "nautakjot": If only beef is offered.
            - "kjuklingur": If only chicken is offered.
            - "blandad best": If both beef and chicken are offered.
    """

    # Check if both beef and chicken are offered.
    if "nautakjot" in meat_types and "kjuklingur" in meat_types:
        return "blandad best"  # Mixed meat

    # If only one type is offered, return that type.
    return meat_types[0]


# Get the number of meat types offered.
num_meat_types = int(input())

# Get the list of meat types offered.
meat_types = []
for _ in range(num_meat_types):
    meat_types.append(input())

# Determine the type of meat Níels got.
niels_meat = get_niels_meat(meat_types)

# Print the type of meat Níels got.
print(niels_meat)
