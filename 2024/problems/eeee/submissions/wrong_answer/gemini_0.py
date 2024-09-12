#!/usr/bin/python3


def get_complexity(acronyms, acronym):
    """
    Calculates the complexity of an acronym recursively.

    Args:
        acronyms: A dictionary mapping acronyms to lists of words they refer to.
        acronym: The acronym to find the complexity for.

    Returns:
        The complexity of the acronym (number of further acronyms to define).
    """
    if acronym not in acronyms:
        return 0
    if not acronyms[acronym]:
        return 0

    complexity = 0
    for word in acronyms[acronym]:
        if word.isupper():
            complexity += get_complexity(acronyms, word) + 1
    return complexity


def main():
    """
    Reads the input, calculates and prints the complexity of each acronym.
    """
    n = int(input())
    acronyms = {}
    for _ in range(n):
        line = input().split()
        acronym, _, acronyms[acronym] = line[0], line[1], line[2:]
    for acronym in acronyms:
        print(get_complexity(acronyms, acronym))


if __name__ == "__main__":
    main()
