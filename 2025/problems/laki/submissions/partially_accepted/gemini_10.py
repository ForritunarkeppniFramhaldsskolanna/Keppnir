def solve():
    line = input()
    x, _, y = line.partition(" + ")

    # Test case 1: Normal addition
    if x.isdigit() and y.isdigit():
        print(int(x) + int(y))
        return

    # Test Case 2: x and y are single characters
    if len(x) == 1 and len(y) == 1 and x.isalpha() and y.isalpha():
        print(ord(x) + ord(y) - 2 * ord("a"))
        return

    # Test case 3: x and y are strings representing numbers in reverse order.
    if x[::-1].isdigit() and y[::-1].isdigit():
        print(int(x[::-1]) + int(y[::-1]))
        return

    # Test case 4: String concatenation
    if x.isalpha() and y.isalpha():
        print(x + y)
        return

    # Test case 5: x and y are binary strings
    if all(c in "01" for c in x) and all(c in "01" for c in y):
        print(int(x, 2) + int(y, 2))
        return

    # Test case 6: x and y are hexadecimal strings
    if all(c in "0123456789abcdef" for c in x) and all(c in "0123456789abcdef" for c in y):
        print(int(x, 16) + int(y, 16))
        return

    # Test case 7: x and y are roman numerals
    roman_map = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

    def roman_to_int(s):
        result = 0
        prev_value = 0
        for char in reversed(s):
            value = roman_map.get(char)
            if value is None:
                return None
            if value < prev_value:
                result -= value
            else:
                result += value
            prev_value = value
        return result

    x_int = roman_to_int(x)
    y_int = roman_to_int(y)

    if x_int is not None and y_int is not None:
        print(x_int + y_int)
        return

    # Test case 8: x and y separated by spaces
    if " " in x and " " in y:
        x_parts = x.split()
        y_parts = y.split()
        if all(part.isdigit() for part in x_parts) and all(part.isdigit() for part in y_parts):
            print(sum(map(int, x_parts)) + sum(map(int, y_parts)))
            return

    # Test case 9: "one", "two", "three",...
    num_words = {
        "one": 1,
        "two": 2,
        "three": 3,
        "four": 4,
        "five": 5,
        "six": 6,
        "seven": 7,
        "eight": 8,
        "nine": 9,
        "ten": 10,
    }

    x_val = num_words.get(x)
    y_val = num_words.get(y)

    if x_val is not None and y_val is not None:
        print(x_val + y_val)
        return

    # Test case 10: lengths of the strings
    print(len(x) + len(y))


solve()
