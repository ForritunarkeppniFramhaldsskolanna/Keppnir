#!/usr/bin/python3

import sys

def determine_rounding_or_truncating(input_num, result_num):
    input_str, result_str = str(input_num), str(result_num)
    input_decimal_places = len(input_str.split('.')[1]) if '.' in input_str else 0
    result_decimal_places = len(result_str.split('.')[1]) if '.' in result_str else 0

    # Round the input number to the same number of decimal places as the result
    rounded_num = round(input_num, result_decimal_places)

    # Truncate the input number by first multiplying to shift the decimal, then divide back
    trunc_factor = 10**input_decimal_places
    truncated_num = int(input_num * trunc_factor) // trunc_factor
    truncated_num = truncated_num / (10**result_decimal_places)

    if rounded_num == result_num:
        if truncated_num != result_num:
            return "Runnun"
        else:
            return "Veit ekki"
    else:
        if truncated_num == result_num:
            return "Styfun"
        else:
            return "Veit ekki"

# Reading from stdin
input_num = float(sys.stdin.readline().strip())
result_num = float(sys.stdin.readline().strip())

# Determine and print the method to stdout
print(determine_rounding_or_truncating(input_num, result_num))

