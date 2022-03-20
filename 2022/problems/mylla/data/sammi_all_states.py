#!/usr/bin/python3
board = ["_" for i in range(9)]

final = set()

d = {0: "_", 1: "x", 2: "o"}

def print_board(board):
	c = 0
	for i in range(3):
		print(board[c:c+3])
		c += 3

def check_win(board):
	owin = False
	c = 0
	if board[0] == board[4] == board[8] and board[0] != "_":
		if board[0] == "o": owin = True
		c += 1
	if board[2] == board[4] == board[6] and board[2] != "_":
		if board[2] == "o": owin = True
		c += 1
	for i in range(3):
		if board[i*3] == board[i*3+1] == board[i*3+2] and board[i*3] != "_":
			if board[i*3] == "o": owin = True
			c += 1
		if board[i] == board[i+3] == board[i+6] and board[i] != "_":
			if board[i] == "o": owin = True
			c += 1

	return c, owin

def check_valid(board, move):
	if move == "x":
		if board.count("o") == board.count("x") - 1:
			return True
	else:
		if board.count("o") == board.count("x"):
			return True
	
	return False

states = set()

for i in range(3**9):
	c = i
	s = ""
	for j in range(9):
		s += d[c % 3]
		c//=3

	states.add(s)

xw = set()
ow = set()
draw = set()

for i in states:
	if check_win(i)[0] == 1:
		if check_win(i)[1]:
			if check_valid(i, "o"):
				ow.add(i)
		else:
			if check_valid(i, "x"):
				xw.add(i)
		#print_board(i)
		#print("-"*15)
	elif check_valid(i, "x") and i.count("_") == 0 and check_win(i)[0] == 0:
		draw.add(i)
		print_board(i)
		print("-"*15)

print(len(draw))
print(len(ow))
print(len(xw))
