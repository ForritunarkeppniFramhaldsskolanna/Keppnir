#!/usr/bin/python3
def find_book(books, titles):
    """
    Finds the location of books in a library.

    Args:
      books: A list of tuples, where each tuple contains the title and author of a book.
      titles: A list of book titles to search for.

    Returns:
      A list of integers, where each integer represents the location of the corresponding book in the library,
      or -1 if the book is not available.
    """

    # Sort the books by author and then by title.
    sorted_books = sorted(books, key=lambda x: (x[1].lower(), x[0].lower()))

    # Create a dictionary to map book titles to their locations in the library.
    book_locations = {book[0]: i for i, book in enumerate(sorted_books)}

    # Find the locations of the books Hallgerður wants to read.
    locations = []
    for title in titles:
        location = book_locations.get(title)
        locations.append(location if location is not None else -1)

    return locations


# Sample input
n, q = map(int, input().split())
books = []
titles = []
for _ in range(n):
    book = (input().split())
    books.append(book)

for _ in range(q):
    titles.append(input())

# Get the locations of the books
locations = find_book(books, titles)

# Print the locations
for location in locations:
    print(location)
