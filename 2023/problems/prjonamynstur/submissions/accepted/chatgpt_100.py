#!/usr/bin/python3
# Read input
n, m = map(int, input().split())
recipe = [input() for _ in range(n)]

# Define yarn usage per loop type
yarn_usage = {
    '.': 20,    # Garter stitch
    'O': 10,    # Yarn over
    '\\': 25,   # Slip one stitch, knit next stitch and pass slip stitch over knit stitch
    '/': 25,    # Knit two stitches together
    'A': 35,    # Knit three stitches together
    '^': 5,     # No stitch
    'v': 22     # Purl on right side, knit on wrong side
}

# Calculate total yarn usage
total_yarn = sum(yarn_usage[symbol] for row in recipe for symbol in row)

# Print result
print(total_yarn)

