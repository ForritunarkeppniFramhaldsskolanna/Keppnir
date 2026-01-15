def main():
    import sys

    data = sys.stdin.read().splitlines()
    if not data:
        return
    # First line: n, l, t
    n, l, t = map(int, data[0].split())
    K = l * t  # Maximum keys per message

    # Second line: the words
    if len(data) < 2:
        return
    words = data[1].split()

    lines = []  # To store our output lines
    current_line_words = []  # Words in the current line
    current_line_cost = 0  # Total cost of current line (words + spaces + enter)

    for word in words:
        # The cost of a word if it is the only word in a line: word length + enter
        word_cost = len(word) + 1
        if word_cost > K:
            print("/ff")
            return

        if not current_line_words:
            # Start a new line with the current word.
            current_line_words.append(word)
            current_line_cost = len(word) + 1  # word + enter
        else:
            # If we add this word, we need an extra space before it.
            if current_line_cost + (len(word) + 1) <= K:
                current_line_words.append(word)
                current_line_cost += len(word) + 1
            else:
                # Cannot add the word in the current line, so finish this line.
                lines.append(" ".join(current_line_words))
                current_line_words = [word]
                current_line_cost = len(word) + 1

    # Append the last line if not empty.
    if current_line_words:
        lines.append(" ".join(current_line_words))

    # Output the message in the fewest number of lines.
    for line in lines:
        print(line)


if __name__ == "__main__":
    main()
