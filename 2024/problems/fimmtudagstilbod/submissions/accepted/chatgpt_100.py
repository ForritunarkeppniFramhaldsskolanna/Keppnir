#!/usr/bin/python3
def calculate_offer_price(y):
    initial_price = 1000  # Initial price in ISK
    price_increase_start_year = 2020  # The year when price increase starts
    annual_increase = 100  # Annual price increase in ISK

    if y < price_increase_start_year:
        # If the year is before the price increase starts, the price remains the initial price
        return initial_price
    else:
        # Calculate the number of years since the price started increasing and the total increase
        years_since_increase = y - price_increase_start_year
        total_increase = years_since_increase * annual_increase
        return initial_price + total_increase

# Input reading
y = int(input())

# Calculate and print the price
print(calculate_offer_price(y))
