#!/usr/bin/python3
def price_of_offer(year):
    """
    Calculates the price of the Thursday offer in a given year.

    Args:
        year: The year for which to calculate the price.

    Returns:
        The price of the Thursday offer in ISK.
    """

    # Base price in 1993
    base_price = 1000

    # Number of years with increased price (inclusive)
    years_with_increase = year - 2019

    # Price increase per year
    price_increase = 100

    # Total price increase since 2020
    total_increase = (
        max(0, years_with_increase) * price_increase
    )  # Apply increase only from 2020

    # Current price
    current_price = base_price + total_increase

    return current_price


# Example usage
year = int(input())
price = price_of_offer(year)
print(price)
