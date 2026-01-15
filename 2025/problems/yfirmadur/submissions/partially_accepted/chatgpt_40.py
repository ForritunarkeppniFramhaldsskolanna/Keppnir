import sys
import heapq

data = sys.stdin.read().split()
if not data:
    exit(0)
it = iter(data)
n = int(next(it))
q = int(next(it))

# Maximum possible employee id: initial n + up to q additions.
max_size = n + q + 5

# boss[i] stores the immediate boss assigned at hiring.
boss = [0] * (max_size)
# par[i] is used for union-find.
# For an active employee, par[i] == i.
# When an employee quits, we set par[i] = find(boss[i]).
par = [0] * (max_size)

# Read initial boss assignments (employees 1...n).
for i in range(1, n + 1):
    b = int(next(it))
    boss[i] = b
    par[i] = i

# min-heap for recycled employee numbers (when employees quit)
available = []
# next_new will be used if no recycled id is available.
next_new = n + 1


def find(x):
    # Iterative version of union-find with path compression.
    root = x
    while par[root] != root:
        root = par[root]
    # Path compression
    while x != root:
        nxt = par[x]
        par[x] = root
        x = nxt
    return root


output_lines = []
for _ in range(q):
    typ = next(it)
    x = int(next(it))
    if typ == "+":
        # Add a new employee with boss x.
        if available:
            new_id = heapq.heappop(available)
        else:
            new_id = next_new
            next_new += 1
        boss[new_id] = x
        par[new_id] = new_id  # new employee is active
    elif typ == "-":
        # Employee x quits.
        par[x] = find(boss[x])
        heapq.heappush(available, x)
    elif typ == "?":
        # Query: output the effective immediate boss of employee x.
        effective_boss = find(boss[x])
        output_lines.append(str(effective_boss))

sys.stdout.write("\n".join(output_lines))
