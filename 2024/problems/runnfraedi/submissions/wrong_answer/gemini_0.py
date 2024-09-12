#!/usr/bin/python3
def determine_method(original, shortened):
    decimals = len(shortened.split(".")[1])  # Number of decimal places in shortened

    truncated = int(original * 10**decimals) / 10**decimals
    rounded = round(original, decimals)

    if truncated == float(shortened):
        return "Styfun"
    elif rounded == float(shortened):
        return "Runnun"
    else:
        return "Veit ekki"


# Input and output (remains the same)
value1 = float(input())
value2 = float(input())
result = determine_method(value1, str(value2))
print(result)
