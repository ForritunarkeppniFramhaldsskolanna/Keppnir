def main():
    import sys

    # Read input from standard input
    data = sys.stdin.read().strip().split()
    if not data:
        return
    R, G, B = map(int, data)

    # Check if all values are equal
    if R == G == B:
        if R == 0:
            print("svartur")
        elif R == 255:
            print("hvitur")
        else:
            print("grar")
    # Check which value is strictly greater than the others
    elif R > G and R > B:
        print("raudur")
    elif G > R and G > B:
        print("graenn")
    elif B > R and B > G:
        print("blar")
    # Check for two equal values with the third strictly smaller
    elif R == G and B < R:
        print("gulur")
    elif R == B and G < R:
        print("fjolubleikur")
    elif G == B and R < G:
        print("blagraenn")
    # If none of the above conditions apply, output "othekkt"
    else:
        print("othekkt")


if __name__ == "__main__":
    main()
