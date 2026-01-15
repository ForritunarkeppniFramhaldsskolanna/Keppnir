def solve():
    import sys

    # Read dimensions h, w, d from a single line
    line = sys.stdin.readline().strip()
    h, w, d = map(int, line.split())

    # Overall "canvas" size:
    #   height = h + d + 1
    #   width  = w + d + 1
    R = h + d + 1
    C = w + d + 1

    # Initialize the grid with spaces
    grid = [[" " for _ in range(C)] for _ in range(R)]

    def overlay(old_char, new_char):
        """
        Decide which character to use if new_char is placed
        over old_char, according to the rules:
          1) '+' (corner) overrides everything.
          2) Existing '+' stays if new_char is not '+'.
          3) 'x' remains if already set, unless a new '+' arrives.
          4) '-' or '|' overlapping with '/' => 'x'.
          5) Same character repeated => that character.
        """
        if new_char == "+":
            return "+"
        if old_char == "+":
            return "+"
        if old_char == " ":
            return new_char
        if old_char == "x":
            # Already marked as overlap
            # (unless we have a corner coming in, but that is handled above)
            return "x"
        if new_char == " ":
            return old_char
        # If both are the same (e.g. '-' over '-'), keep it
        if old_char == new_char:
            return old_char
        # Otherwise, it's an overlap => 'x'
        return "x"

    def place(r, c, ch):
        """Place character ch into grid[r][c], respecting overlap rules."""
        grid[r][c] = overlay(grid[r][c], ch)

    #
    # 1) Draw the front face (bottom-left in our coordinate system)
    #
    # Corners
    place(d, 0, "+")
    place(d, w, "+")
    place(h + d, 0, "+")
    place(h + d, w, "+")
    # Horizontal edges of front face
    for col in range(1, w):
        place(d, col, "-")
        place(h + d, col, "-")
    # Vertical edges of front face
    for row in range(d + 1, h + d):
        place(row, 0, "|")
        place(row, w, "|")

    #
    # 2) Draw the back face (top-right in our coordinate system)
    #
    # Corners
    place(0, d, "+")
    place(0, d + w, "+")
    place(h, d, "+")
    place(h, d + w, "+")
    # Horizontal edges of back face
    for col in range(d + 1, d + w):
        place(0, col, "-")
        place(h, col, "-")
    # Vertical edges of back face
    for row in range(1, h):
        place(row, d, "|")
        place(row, d + w, "|")

    #
    # 3) Draw the four diagonal edges (the "depth" edges) with '/'
    #
    def draw_diagonal(r_front, c_front):
        """
        From the front corner (r_front, c_front) up and right d steps
        to the corresponding back corner, place '/' in between.
        We only place slashes for the *interior* points (1..d-1),
        because the endpoints are already corners ('+').
        """
        for i in range(1, d):
            rr = r_front - i
            cc = c_front + i
            place(rr, cc, "/")

    # Four front corners -> back corners
    draw_diagonal(h + d, 0)  # bottom-left
    draw_diagonal(h + d, w)  # bottom-right
    draw_diagonal(d, 0)  # top-left
    draw_diagonal(d, w)  # top-right

    #
    # 4) Output the result
    #    - Right-strip trailing spaces on each line
    #    - Remove empty lines from the bottom only
    #
    lines = []
    for r in range(R):
        row_str = "".join(grid[r]).rstrip()
        lines.append(row_str)

    # Remove trailing empty lines from the bottom
    while lines and lines[-1] == "":
        lines.pop()

    # Print the final lines
    for ln in lines:
        print(ln)


# If you want to test quickly by running this as a script,
# you can uncomment the lines below and provide sample input:
#
if __name__ == "__main__":
    #     # Example: h=2, w=3, d=2
    #     import io
    #     import sys
    #     input_data = """2 3 2"""
    #     sys.stdin = io.StringIO(input_data)
    solve()
