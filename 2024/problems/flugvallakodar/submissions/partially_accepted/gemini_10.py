#!/usr/bin/python3
def get_aans_code(airport_name, used_codes):
    """
    Determines the AANS code for an airport, considering existing codes.

    Args:
        airport_name (str): The name of the airport.
        used_codes (set): A set of already used AANS codes.

    Returns:
        str: The valid AANS code for the airport, or ":(" if none exists.
    """

    code = airport_name[:3]
    if code not in used_codes:
        return code

    for i in range(1, len(airport_name)):
        for j in range(i, len(airport_name)):
            for k in range(j, len(airport_name)):
                candidate_code = (
                    airport_name[i : i + 1]
                    + airport_name[j : j + 1]
                    + airport_name[k : k + 1]
                )
                if candidate_code not in used_codes:
                    return candidate_code

    return ":("


def main():
    """
    Reads airport names from input, determines their AANS codes, and prints the results.
    """

    n = int(input())
    used_codes = set()

    for _ in range(n):
        airport_name = input().upper()
        aans_code = get_aans_code(airport_name, used_codes)
        print(aans_code)
        used_codes.add(aans_code)


if __name__ == "__main__":
    main()
