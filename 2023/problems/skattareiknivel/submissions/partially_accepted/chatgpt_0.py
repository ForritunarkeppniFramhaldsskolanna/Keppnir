#!/usr/bin/python3
import math

# Read input
pension_percentage = float(input())
property_percentage = float(input())
salaries = [int(input()) for _ in range(12)]

# Constants
personal_tax_exemption = 59665
communal_tax = 0.1467

# Calculate total withholding tax for given salary
def calculate_withholding_tax(salary):
    if salary <= 409986:
        return 0.1678 * salary
    elif salary <= 1151012:
        return 0.1678 * 409986 + 0.2328 * (salary - 409986)
    else:
        return 0.1678 * 409986 + 0.2328 * (1151012 - 409986) + 0.3158 * (salary - 1151012)

# Calculate total withholding tax and personal tax exemption for given salary and previous exemption
def calculate_tax(salary, previous_exemption):
    tax_base = salary * (1 - pension_percentage - property_percentage)
    fund_fees = salary * (pension_percentage + property_percentage)
    withholding_tax = calculate_withholding_tax(math.floor(max(0, tax_base)))
    available_exemption = personal_tax_exemption + previous_exemption
    if withholding_tax <= available_exemption:
        return (0, available_exemption - withholding_tax)
    else:
        return (math.floor((withholding_tax - available_exemption) / (1 - communal_tax)), 0)

# Iterate over all salaries and calculate total after taxes and fees
total_salary = sum(salaries)
total_tax = 0
previous_exemption = 0
for salary in salaries:
    tax, previous_exemption = calculate_tax(salary, previous_exemption)
    total_tax += tax

total_salary -= total_salary * (pension_percentage + property_percentage) + total_tax

# Print result
print(math.floor(total_salary))

