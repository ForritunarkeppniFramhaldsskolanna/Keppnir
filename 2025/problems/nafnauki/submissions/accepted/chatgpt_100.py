def main():
    import sys

    # Read the file name from standard input and remove any extra whitespace
    filename = sys.stdin.read().strip()

    # Find the index of the last dot in the file name
    last_dot_index = filename.rfind(".")

    # Extract the extension including the dot
    extension = filename[last_dot_index:]

    # Output the extension
    sys.stdout.write(extension)


if __name__ == "__main__":
    main()
