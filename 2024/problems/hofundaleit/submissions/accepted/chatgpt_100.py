#!/usr/bin/python3
# Read the number of books in the library and the number of books Hallgerður wants to read
n, q = map(int, input().split())

# Read the details of each book in the library
library_books = []
for _ in range(n):
    book_detail = input().strip()
    title, author = book_detail.split(", ")
    # Append a tuple of (author, title) for sorting purposes
    library_books.append((author, title))

# Sort the books first by author, then by title
library_books.sort()

# Prepare a dictionary to quickly find the position of a book by its title
books_index = {title: i+1 for i, (_, title) in enumerate(library_books)}

# For each book Hallgerður wants to read, print its location or -1 if not found
for _ in range(q):
    wanted_title = input().strip()
    print(books_index.get(wanted_title, -1))

