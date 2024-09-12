#!/usr/bin/python3
import math
def compare_pizza_sizes(d, a, b, h):
    # Calculate the area of the round pizza
    radius = d / 2
    area_mahjong = 3.141593 * (radius ** 2)

    # Calculate the area of the trapezoid pizza
    area_trapizza = ((a + b) / 2) * h

    # Compare the areas and output the result
    if area_mahjong > area_trapizza:
        return "Mahjong!"
    elif area_trapizza > area_mahjong:
        return "Trapizza!"
    else:
        return "Jafn storar!"

def compare_pizza_sizes_pi(d, a, b, h):
    # Calculate the area of the round pizza
    radius = d / 2
    area_mahjong = math.pi * (radius ** 2)

    # Calculate the area of the trapezoid pizza
    area_trapizza = ((a + b) / 2) * h

    # Compare the areas and output the result
    if area_mahjong > area_trapizza:
        return "Mahjong!"
    elif area_trapizza > area_mahjong:
        return "Trapizza!"
    else:
        return "Jafn storar!"

for d in range(0, 101):
    for a in range(0, 101):
        for b in range(0, 101):
            for h in range(0, 101):
                if compare_pizza_sizes(d, a, b, h) != compare_pizza_sizes_pi(d, a, b, h):
                    print(d, a, b, h)


# Read inputs from stdin
#d = int(input())
#a = int(input())
#b = int(input())
#h = int(input())

# Perform the comparison and print the result to stdout
#compare_pizza_sizes(d, a, b, h)
