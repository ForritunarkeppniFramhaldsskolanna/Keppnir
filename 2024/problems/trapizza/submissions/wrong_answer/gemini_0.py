#!/usr/bin/python3
def calculate_round_pizza_area(diameter):
    radius = diameter / 2
    return 3.14159 * radius * radius  # Using pi = 3.14159


def calculate_trapezoid_pizza_area(side_a, side_b, height):
    return ((side_a + side_b) / 2) * height


# Input
diameter = int(input())
side_a = int(input())
side_b = int(input())
height = int(input())

# Calculate Areas
mahjong_area = calculate_round_pizza_area(diameter)
trapizza_area = calculate_trapezoid_pizza_area(side_a, side_b, height)

# Compare and Output
if trapizza_area > mahjong_area:
    print("Trapizza!")
elif mahjong_area > trapizza_area:
    print("Mahjong!")
else:
    print("Jafn storar!")
