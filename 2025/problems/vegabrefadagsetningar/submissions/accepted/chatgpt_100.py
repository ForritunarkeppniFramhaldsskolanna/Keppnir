def solve():
    import sys

    # Mapping from English month abbreviations to month numbers.
    month_map = {
        "JAN": "01",
        "FEB": "02",
        "MAR": "03",
        "APR": "04",
        "MAY": "05",
        "JUN": "06",
        "JUL": "07",
        "AUG": "08",
        "SEP": "09",
        "OCT": "10",
        "NOV": "11",
        "DEC": "12",
    }

    # Read the single line input.
    line = sys.stdin.readline().strip()
    if not line:
        return

    # Split the input into its parts.
    parts = line.split()
    # parts[0] is the day (e.g., "08")
    # parts[1] is the Icelandic month abbreviation (not needed)
    # parts[2] is the English month abbreviation with a preceding slash (e.g., "/MAR")
    # parts[3] is the two-digit year (e.g., "25")

    day = parts[0]
    # Remove the slash from the English month abbreviation.
    en_month_abbr = parts[2][1:]
    year_two_digits = parts[3]

    # Convert the two-digit year to full year (range: 2015-2035).
    year = 2000 + int(year_two_digits)

    # Get the month number string using the English abbreviation.
    month = month_map[en_month_abbr]

    # Print in ISO-8601 format: yyyy-mm-dd.
    sys.stdout.write(f"{year:04d}-{month}-{day}")


solve()
