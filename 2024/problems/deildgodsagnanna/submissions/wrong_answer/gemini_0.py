#!/usr/bin/python3
def modulo(a, b):
    """Calculates the remainder of a divided by b."""
    return a % b


def draft_processes(n):
    """Calculates the number of different draft processes with n champions modulo 1,000,000,007."""
    modulo_value = 1000000007
    banned_scenarios = pow(n, 6, modulo_value)
    picking_scenarios = (
        (n - 6) * (n - 7) * (n - 8) * (n - 9) * (n - 10) * (n - 11) * (n - 11)
    ) % modulo_value
    total_processes = (banned_scenarios * picking_scenarios) % modulo_value
    return total_processes


# Example usage
n = int(input())
result = draft_processes(n)
print("Number of draft processes:", result)
