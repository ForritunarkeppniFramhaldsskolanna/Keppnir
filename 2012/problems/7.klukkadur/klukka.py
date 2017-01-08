#!/usr/bin/python

from collections import deque

def nextBoard(board, rule):
	newBoard = []
	for i in xrange(3):
		newBoard.append([])
		for j in xrange(3):
			newBoard[i].append([])
			newBoard[i][j] = board[i][j] + (3 * rule[i][j])

			if newBoard[i][j] > 12:
				newBoard[i][j] = 3
			
	return newBoard

def bfs(board, rules, goal):
	visited = []
	queue = deque([(board, 0)])
	while queue:
		(currState, depth) = queue.popleft()
		if currState not in visited:
			visited.append(currState)
			if currState == goal:
				return depth

			for rule in rules:
				queue.append((nextBoard(currState, rule), depth + 1))
	return -1

def klukka():
	cases = int(raw_input(""))
	raw_input("")
	for n in xrange(0, cases):
		rules = []
		boards = []
		nRules = int(raw_input(""))

		for r in xrange(0, nRules):
			rules.append([])
			for i in xrange(3):
				 rules[r].append([])
				 l = raw_input("").split(" ")
				 for j in xrange(3):
					rules[r][i].append(int(l[j]))
			raw_input("")
				
		nBoards = int(raw_input(""))

		for r in xrange(0, nBoards):
			boards.append([])
			for i in xrange(3):
				 boards[r].append([])
				 l = raw_input("").split(" ")
				 for j in xrange(3):
					boards[r][i].append(int(l[j]))

			if not r == int(nBoards)-1:
				raw_input("")

		for board in boards:
			d = bfs(board, rules, [[12,12,12],[12,12,12],[12,12,12]])
			if d == -1:
				print "NOT POSSIBLE"
			else:
				print d
				
		if not n == int(cases)-1:
					raw_input("")
			
if __name__ == '__main__':
	klukka()