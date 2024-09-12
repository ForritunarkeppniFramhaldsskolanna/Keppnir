#!/usr/bin/python3
def compare_pizza_sizes(d, a, b, h):
    # Calculate the area of the round pizza
    radius = d / 2
    area_mahjong = 3.142 * (radius ** 2)

    # Calculate the area of the trapezoid pizza
    area_trapizza = ((a + b) / 2) * h

    # Compare the areas and output the result
    if area_mahjong > area_trapizza:
        print("Mahjong!")
    elif area_trapizza > area_mahjong:
        print("Trapizza!")
    else:
        print("Jafn storar!")

# Read inputs from stdin
d = int(input())
a = int(input())
b = int(input())
h = int(input())

# Perform the comparison and print the result to stdout
compare_pizza_sizes(d, a, b, h)
