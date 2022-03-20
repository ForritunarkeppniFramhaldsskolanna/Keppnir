#!/bin/python3
import sys
import timeit
from functools import lru_cache

DEBUG = False

n, m = 0, 0
state = []


UP = 'U'
DOWN = 'D'
LEFT = 'L'
RIGHT = 'R'
QUIT = 'Q'
DIR = {
    UP: (1, 0), 
    DOWN: (-1, 0),
    LEFT: (0, 1),
    RIGHT: (0, -1)
}
INV = {
    UP: DOWN,
    DOWN: UP,
    LEFT: RIGHT,
    RIGHT: LEFT
}

ROW_IND = 0
COL_IND = 1
TOP_ROW = 0



def debug(s):
    if DEBUG:
        sys.stderr.write("{}\n".format(s))


def get_size(state):
    assert len(state) > 0
    return len(state), len(state[0])


def empty(state):
    n, m = get_size(state)
    return n*m


def stringify(val):
    return str(val).zfill(2)


standardize_element = int


def tuplify(state):
    return tuple(tuple(row) for row in state)


def standardize(state):
    """
    Converts the states values to strings of 2 digits
    """
    n, m = get_size(state)
    return tuplify((standardize_element(val) for val in row) for row in state)


def remove_final(state):
    """
    Removes the bottom right corner cell
    """
    return tuplify(state)
    max_val = max(max(state, key=max))
    new_state = [[val if val != max_val else empty(state) for val in row] for row in state]
    return tuplify(new_state)


def print_state(state):
    """
    Prints the state
    """
    for row in state:
        print(' '.join('{:>3}'.format(val) for val in row))


def coords(state, val):
    n, m = get_size(state)
    for y in range(n):
        for x in range(m):
            if state[y][x] == val:
                return y, x


def empty_coords(state):
    """
    Returns the row, col coordinates of the empty cell
    """
    return coords(state, empty(state))


def legal_moves(state):
    """
    Yields all the legal moves in this state state
    """
    n, m = get_size(state)
    y, x = empty_coords(state)
    if y < n-1:
        yield UP
    if y > 0:
        yield DOWN
    if x < m-1:
        yield LEFT
    if x > 0:
        yield RIGHT


class InvalidMove(Exception):
    """
    Exception for invalid move
    """
    pass


def execute_move(state, move):
    """
    Executes the move on the state state and
    returns the new state after execution
    """
    y, x = empty_coords(state)
    legal = tuple(legal_moves(state))
    if move not in legal:
        print_state(state)
        debug(move)
        raise InvalidMove()
    dy, dx = DIR[move]
    ny, nx = y+dy, x+dx
    state = [[val for val in row] for row in state]
    state[ny][nx], state[y][x] = state[y][x], state[ny][nx]
    return tuplify(state)


def read_size():
    n, m = map(int, input().split())
    return n, m


def read_state():
    return tuple(tuple(map(int, input().split())) for _ in range(n))


def read_move():
    return input().upper()


def solved_state(state):
    n, m = get_size(state)
    return solved_state_for_size(n, m)


@lru_cache(maxsize=None)
def solved_state_for_size(n, m):
    solved = [[i*m+j+1 for j in range(m)] for i in range(n)]
    solved = standardize(solved)
    solved = remove_final(solved)
    return solved


def is_solved(state):
    n, m = get_size(state)
    L = [val for row in state for val in row]
    return L[-1] == empty(state) and not any(L[i] < L[i-1] for i in range(1, n*m-1))
    

def trace_bfs_path(initial_state, step):
    """
    Trace the path backwards from solution to initial state
    using the result of the BFS
    """
    solution = []
    current_state = initial_state
    if current_state not in step:
        return None
    while step[current_state] != "":
        move = step[current_state]
        solution.append(move)
        current_state = execute_move(current_state, INV[move])
    return ''.join(solution[::-1])


def bfs_solver(initial_state, predicate=is_solved):
    """
    Find solution with least number of steps using
    Breadth-first search.
    """
    from collections import deque
    debug("bfs_solver called with {}".format(initial_state))
    q = deque([initial_state])
    # Start at 0 moves made
    dist = {initial_state: 0}
    # We did nothing to get to initial state
    step = {initial_state: ""}
    solved = solved_state(initial_state)
    if predicate(initial_state):
        return trace_bfs_path(initial_state, step)
    while len(q) > 0:
        current_state = q.popleft()
        for move in legal_moves(current_state):
            next_state = execute_move(current_state, move)
            if next_state not in dist:
                dist[next_state] = dist[current_state]+1
                step[next_state] = move
                q.append(next_state)
                if predicate(next_state):
                    return trace_bfs_path(next_state, step)
    return None

def sum_of_manhattan_distances(state):
    n, m = get_size(state)
    sm = 0
    for row in range(n):
        for col in range(m):
            zval = state[row][col]-1
            e_row = zval//m
            e_col = zval%m
            sm += abs(row-e_row) + abs(col-e_col)
    return sm

def sum_of_manhattan_distances_weighted_row(state):
    n, m = get_size(state)
    sm = 0
    for row in range(n):
        for col in range(m):
            zval = state[row][col]-1
            e_row = zval//m
            e_col = zval%m
            to_add = (abs(row-e_row) + abs(col-e_col))
            if e_row < 2:
                to_add *= 2
            sm += to_add
    return sm


def number_of_misplaced_tiles(state):
    n, m = get_size(state)
    count = 0
    for i in range(n):
        for j in range(m):
            expected = i*m+j+1
            actual = state[i][j]
            count += (actual != count)
    return count

FOUND = True
NOT_FOUND = None
INF = float('inf')

def idastar_solver(initial_state, h=sum_of_manhattan_distances_weighted_row):
    bound = h(initial_state)
    path = [initial_state]
    vis = {initial_state}
    moves = []
    while True:
        t = ida_search(path, vis, moves, 0, bound, h)
        if t == FOUND:
            return ''.join(moves)
        if t == INF:
            return NOT_FOUND
        bound = t

def ida_search(path, vis, moves, g, bound, h):
    state = path[-1]
    f = g + h(state)
    if f > bound:
        return f
    if is_solved(state):
        return FOUND
    mn = INF
    successors = sorted([(execute_move(state, move), move)
                       for move in legal_moves(state)],
                       key=lambda x: (h(x[0]), x[1]))
    for succ, move in successors:
        if succ not in vis:
            path.append(succ)
            moves.append(move)
            vis.add(succ)
            t = ida_search(path, vis, moves, g + 1, bound, h)
            if t == FOUND:
                return FOUND
            if t < mn:
                mn = t
            vis.remove(succ)
            moves.pop()
            path.pop()
    return mn

def astar_solver(initial_state, h=sum_of_manhattan_distances_weighted_row):
    """
    Find solution with least number of steps using
    Breadth-first search.
    """
    from collections import defaultdict
    from heapq import heappop, heappush
    debug("astar_solver called with {}".format(initial_state))
    openSet = []
    fScore = defaultdict(lambda: float('inf'))
    gScore = defaultdict(lambda: float('inf'))
    fScore[initial_state] = h(initial_state)
    gScore[initial_state] = 0
    entry_finder = {}
    REMOVED = tuple()
    
    def add_to_heap(state):
        if state in entry_finder:
            remove_from_heap(state)
        entry = [fScore[state], state]
        entry_finder[state] = entry
        heappush(openSet, entry)
    
    def remove_from_heap(state):
        entry = entry_finder.pop(state)
        entry[-1] = REMOVED

    def pop_heap():
        while openSet:
            priority, state = heappop(openSet)
            if state is not REMOVED:
                del entry_finder[state]
                return state
        return None
    cameFrom = dict()
    stepToReach = {initial_state: ""}
    
    #heappush(openSet, (fScore[initial_state], initial_state))
    add_to_heap(initial_state)

    while len(openSet) > 0:
        #priority, current = heappop(openSet)
        current = pop_heap()
        if current is None:
            return None
        if is_solved(current):
            return trace_bfs_path(current, stepToReach)
        
        for move in legal_moves(current):
            neighbor = execute_move(current, move)
            tentative_gScore = gScore[current] + 1
            if tentative_gScore < gScore[neighbor]:
                stepToReach[neighbor] = move
                gScore[neighbor] = tentative_gScore
                fScore[neighbor] = tentative_gScore + h(neighbor)
                if neighbor not in openSet:
                    add_to_heap(neighbor)
                    #heappush(openSet, (fScore[neighbor], neighbor))

    return None


def execute_moves(state, moves, move_arr=None):
    for move in moves:
        if move_arr is not None:
            move_arr.append(move)
        state = execute_move(state, move)
    return state


def remove_top_row(state):
    """
    Removes the top row and maps values so
    they are from 1 to n*m
    """
    n, m = get_size(state)
    assert state[0] == tuple(range(1, m+1))
    return tuplify([[val-m for val in row] for row in state[1:]])


def move_empty(state, row, col):
    return move_empty_to_row(state, row) + move_empty_to_col(state, col)

def move_empty_to_row(state, row):
    move_arr = []
    while empty_coords(state)[ROW_IND] < row:
        state = execute_moves(state, UP, move_arr)
    while empty_coords(state)[ROW_IND] > row:
        state = execute_moves(state, DOWN, move_arr)
    return ''.join(move_arr)

def move_empty_to_col(state, col):
    move_arr = []
    while empty_coords(state)[COL_IND] < col:
        state = execute_moves(state, LEFT, move_arr)
    while empty_coords(state)[COL_IND] > col:
        state = execute_moves(state, RIGHT, move_arr)
    return ''.join(move_arr)


def move_empty_to_top(state):
    move_arr = []
    while empty_coords(state)[ROW_IND] != TOP_ROW:
        state = execute_moves(state, DOWN, move_arr)
    return ''.join(move_arr)


def move_empty_above_value(state, val):
    return move_empty_to_col(state, coords(state, val)[COL_IND])


def shift_value_to_top(state, val):
    move_arr = []
    while True:
        while coords(state, val)[ROW_IND] > empty_coords(state)[ROW_IND]:
            state = execute_moves(state, UP, move_arr)
        state = execute_moves(state, LEFT, move_arr)
        state = execute_moves(state, move_empty_to_top(state), move_arr)
        if coords(state, val)[ROW_IND] == TOP_ROW:
            break
        state = execute_moves(state, RIGHT, move_arr)
    return ''.join(move_arr)

def move_value_to_top(state, val):
    debug("move_value_to_top called with {} and {}".format(state, val))
    n, m = get_size(state)
    move_arr = []
    if coords(state, val)[ROW_IND] != TOP_ROW:
        step_1 = move_empty_to_top(state)
        state = execute_moves(state, step_1, move_arr)
        step_2 = move_empty_above_value(state, val)
        state = execute_moves(state, step_2, move_arr)
        step_3 = shift_value_to_top(state, val)
        state = execute_moves(state, step_3, move_arr)
    y, x = coords(state, val)
    while empty_coords(state)[COL_IND] < coords(state, val)[COL_IND]:
        state = execute_moves(state, LEFT, move_arr)
    while empty_coords(state)[COL_IND] > coords(state, val)[COL_IND]+1:
        state = execute_moves(state, RIGHT, move_arr)
    state = execute_moves(state, move_empty_to_row(state, y), move_arr)
    return ''.join(move_arr)


def correct_place_in_top(state, val):
    """
    Handles placing in the top row (not the final one though)
    """
    debug("correct_place_in_top called with {} and {}".format(state, val))
    y,x = coords(state, val)
    move_arr = []
    if x == m-1:
        debug("rightmost column special case")
        state = execute_moves(state, move_empty_to_col(state, x-1), move_arr)
        state = execute_moves(state, move_empty_to_row(state, y), move_arr)
        state = execute_moves(state, LEFT, move_arr)
    elif x < val-1:
        debug("too far left special case")
        state = execute_moves(state, move_empty_to_row(state, y), move_arr)
        state = execute_moves(state, move_value_to_rightmost(state, val, val-1), move_arr)
    state = execute_moves(state, move_value_to_top(state, val), move_arr)
    while coords(state, val)[COL_IND] > val-1:
        state = execute_moves(state, "URRDL", move_arr)
    return ''.join(move_arr)
    

def move_value_to_rightmost(state, val, dest_col=None):
    debug("move_value_to_rightmost called with {}, {} and {}".format(state, val, dest_col))
    n, m = get_size(state)
    if dest_col is None:
        dest_col = m-1
    move_arr = []
    y, x = coords(state, val)
    while x < dest_col:
        state = execute_moves(state, move_empty_to_col(state, x), move_arr)
        state = execute_moves(state, DOWN if y == n-1 else UP, move_arr)
        state = execute_moves(state, move_empty_to_col(state, dest_col), move_arr)
        state = execute_moves(state, UP if y == n-1 else DOWN, move_arr)
        y,x = coords(state, val)
    return ''.join(move_arr)

def correct_place_in_top_final(state, val):
    """
    Handles the final placement in the top row
    """
    n, m = get_size(state)
    y,x = coords(state, val)
    if (y,x) == (1, m-1):
        return "U"
    move_arr = []
    if x != m-1:
        state = execute_moves(state, move_empty_to_row(state, y), move_arr)
        state = execute_moves(state, move_value_to_rightmost(state, val), move_arr)
    state = execute_moves(state, move_empty_to_row(state, TOP_ROW), move_arr)
    state = execute_moves(state, "RUL", move_arr) 
    y,x = coords(state, val)
    debug(state)
    while y != 2:
        state = execute_moves(state, move_empty_to_row(state, y), move_arr)
        state = execute_moves(state, RIGHT, move_arr)
        state = execute_moves(state, move_empty_to_row(state, 1), move_arr)
        state = execute_moves(state, LEFT, move_arr)
        y,x = coords(state, val)
    state = execute_moves(state, "URDDLU", move_arr)
    return ''.join(move_arr)


def solve_top_row(state):
    """
    This only works for states with 3 or more rows.
    Finds the steps required to solve the top row.
    Returns the steps taken and a sub-problem where
    the top row has been removed. 
    """
    debug("solve_top_row called with {}".format(state))
    n, m = get_size(state)
    move_arr = []
    for val in range(1, m+1):
        if val < m:
            state = execute_moves(state, correct_place_in_top(state, val), move_arr)
        else:
            debug(state)
            state = execute_moves(state, correct_place_in_top_final(state, val), move_arr)
    return ''.join(move_arr), remove_top_row(state)


def remove_left_col(state):
    """
    Removes the leftmost column and maps values so
    they are from 1 to n*m
    """
    n, m = get_size(state)
    assert state[0][0] == 1
    assert state[1][0] == m+1
    return tuplify([[val-1 if val <= m else val-2 for val in row[1:]] for row in state])


def solve_left_col_part_1(state):
    debug("solve_left_col_part_1 called with {}".format(state))
    n, m = get_size(state)
    TARGET = (0,0)
    TOP_ROW = 0
    BOTTOM_ROW = n-1
    EMPTY_STOP = (1,0)
    move_arr = []
    val = m+1
    if coords(state, val)[ROW_IND] == BOTTOM_ROW:
        if empty_coords(state) == BOTTOM_ROW:
            state = execute_moves(state, DOWN, move_arr)
        while coords(state, val)[COL_IND] < empty_coords(state)[COL_IND]:
            state = execute_moves(state, RIGHT, move_arr)
        while coords(state, val)[COL_IND] > empty_coords(state)[COL_IND]: 
            state = execute_moves(state, LEFT, move_arr)
    if empty_coords(state)[ROW_IND] == TOP_ROW:
        state = execute_moves(state, UP, move_arr)
    val_coords = coords(state, val)
    while val_coords != TARGET:
        while empty_coords(state) != EMPTY_STOP:
            state = execute_moves(state, RIGHT, move_arr)
        state = execute_moves(state, DOWN, move_arr)
        while val_coords[COL_IND] > empty_coords(state)[COL_IND]:
            state = execute_moves(state, LEFT, move_arr)
        state = execute_moves(state, UP, move_arr)
        val_coords = coords(state, val)

    return ''.join(move_arr)


def solve_left_col_part_2(state):
    debug("solve_left_col_part_2 called with {}".format(state))
    n, m = get_size(state)
    val = 1
    TARGET = (0,1)
    SPECIAL = (1,0)
    EMPTY_STOP = (1,1)
    TOP_ROW = 0
    BOTTOM_ROW = n-1
    SPECIAL_FIX = "RDLULDRRULDL"
    val_coords = coords(state, val)
    if val_coords == TARGET:
        return ""
    elif val_coords == SPECIAL:
        return move_empty(state, 1, 1) + SPECIAL_FIX

    move_arr = []
    if coords(state, val)[ROW_IND] == BOTTOM_ROW:
        if empty_coords(state) == BOTTOM_ROW:
            state = execute_moves(state, DOWN, move_arr)
        while coords(state, val)[COL_IND] < empty_coords(state)[COL_IND]:
            state = execute_moves(state, RIGHT, move_arr)
        while coords(state, val)[COL_IND] > empty_coords(state)[COL_IND]: 
            state = execute_moves(state, LEFT, move_arr)
    if empty_coords(state)[ROW_IND] == TOP_ROW:
        state = execute_moves(state, UP, move_arr)
    val_coords = coords(state, val)

    if val_coords == SPECIAL:
        state = execute_moves(state, move_empty(state, 1, 1) + SPECIAL_FIX, move_arr)
    else:
        if empty_coords(state) == SPECIAL:
            state = execute_moves(state, LEFT, move_arr)
        while val_coords != TARGET:
            while empty_coords(state) != EMPTY_STOP:
                state = execute_moves(state, RIGHT, move_arr)
            state = execute_moves(state, DOWN, move_arr)
            while val_coords[COL_IND] > empty_coords(state)[COL_IND]:
                state = execute_moves(state, LEFT, move_arr)
            state = execute_moves(state, UP, move_arr)
            val_coords = coords(state, val)

    return ''.join(move_arr)
    

def solve_left_col(state):
    """
    This only works for states with 2 rows.
    Finds the steps required to solve the leftmost column.
    Returns the steps taken and a sub-problem where
    the leftmost column has been removed.
    """
    debug("solve_left_col called with {}".format(state))
    if len(state[0]) == 1:
        return solve_base_case(state)

    move_arr = []
    
    moves = solve_left_col_part_1(state)
    state = execute_moves(state, moves, move_arr)

    moves = solve_left_col_part_2(state)
    state = execute_moves(state, moves, move_arr)
    
    if empty_coords(state)[0] == 0:
        state = execute_moves(state, UP, move_arr)
    while empty_coords(state) != (1,0):
        state = execute_moves(state, RIGHT, move_arr)
    state = execute_moves(state, DOWN, move_arr)
    state = execute_moves(state, LEFT, move_arr)

    moves = ''.join(move_arr)
    return moves, remove_left_col(state)


def solve_base_case(state):
    """
    This only works for state with 2 rows, 1 column.
    If the empty cell is in the top row we make an UP move.
    Otherwise it is already solved.
    """
    debug("solve_base_case called with {}".format(state))
    if not is_solved(state):
        return "U", []
    else:
        return "", []


def solvable(state):
    n, m = get_size(state)
    state = execute_moves(state, move_empty(state, n-1, m-1))
    L = [val for row in state for val in row]
    inversions = 0
    for i in range(len(L)):
        for j in range(i+1, len(L)):
            if L[i] > L[j]:
                inversions += 1
    return inversions % 2 == 0


def strategic_solver(state):
    if not solvable(state):
        return None
    step_arr = []
    try:
        while state:
            n, m = get_size(state)
            if n > 2:
                steps, state = solve_top_row(state)
                step_arr.append(steps)
            elif n == 2:
                steps, state = solve_left_col(state)
                step_arr.append(steps)
            else:
                assert False
    except InvalidMove as e:
        raise e
    return ''.join(step_arr)


def verify_solution(state, solution):
    state = execute_moves(state, solution)
    return is_solved(state)


def trim_solution(solution):
    sol_arr = []
    for c in solution:
        if len(sol_arr) > 0 and INV[c] == sol_arr[-1]:
            sol_arr.pop()
        else:
            sol_arr.append(c)
    return ''.join(sol_arr)


def use_solver(state, solver):
    debug("Using solver: {}".format(solver.__name__))
    solution = None
    if solvable(state):
        solution = solver(state)
    if solution == None:
        print("impossible")
    else:
        debug("Solution length: {}".format(len(solution)))
        debug("Solution: \"{}\"".format(solution))
        if verify_solution(state, solution):
            debug("Solution verified")
        trimmed_solution = trim_solution(solution)
        debug("Trimmed length: {}".format(len(trimmed_solution)))
        debug("Trimmed:  \"{}\"".format(trimmed_solution))
        if verify_solution(state, trimmed_solution):
            debug("Solution verified")
        print(trimmed_solution)


if __name__ == "__main__":
    n, m = read_size()
    state = read_state()
    state = standardize(state)
    state = remove_final(state)
    #if n*m <= 10:
    #    use_solver(state, bfs_solver)
    #use_solver(state, strategic_solver)
    use_solver(state, idastar_solver)
    """
    print_state(state)
    cmd = read_move()
    while cmd != QUIT:
        try:
            state = execute_move(state, cmd)
            if is_solved(state):
                print("Solved")
            else:
                print("Unsolved")
        except InvalidMove:
            print("Error")
        print_state(state)
        cmd = read_move()
    """
