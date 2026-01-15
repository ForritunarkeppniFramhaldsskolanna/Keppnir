def solve():
    import sys
    import math
    from bisect import bisect_left
    from collections import deque

    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    # Read input parameters.
    N = int(next(it))
    X = int(next(it))
    Y = int(next(it))
    H = int(next(it))
    S = int(next(it))

    # Marathon distance in metres.
    D = 42195

    # Read station positions; consider only stations strictly between 0 and D.
    stations = []
    for _ in range(N):
        pos = int(next(it))
        if 0 < pos < D:
            stations.append(pos)

    # Special cases.
    if X == 0:
        # No water in pouch -> always jog at speed S.
        tot = D / S
        tot_sec = int(tot)  # here using truncation is natural.
        hh = tot_sec // 3600
        mm = (tot_sec % 3600) // 60
        ss = tot_sec % 60
        sys.stdout.write(f"{hh:02d}:{mm:02d}:{ss:02d}")
        return

    if X >= D:
        # Pouch lasts whole marathon: run at speed H.
        tot = D / H
        tot_sec = int(tot)
        hh = tot_sec // 3600
        mm = (tot_sec % 3600) // 60
        ss = tot_sec % 60
        sys.stdout.write(f"{hh:02d}:{mm:02d}:{ss:02d}")
        return

    # Build list of “full–bag” states: start, all station positions, finish.
    pts = set()
    pts.add(0)
    pts.add(D)
    for pos in stations:
        pts.add(pos)
    states = sorted(pts)
    M = len(states)

    INF = 10**18
    dp = [INF] * M
    dp[0] = 0  # At start, time = 0 ticks.

    # Compute L = lcm(H, S). Since H, S <= 10, this is very small.
    L = (H * S) // math.gcd(H, S)
    # Define A and B (they will be integers because L is a multiple of both H and S).
    A = L // H  # so d/H becomes d*A ticks.
    B = L // S  # so d/S becomes d*B ticks.

    Yticks = Y * L  # refill cost in ticks.

    # We'll maintain two helpers:
    # 1. A deque for candidate 1: indices j with states[j] in [p_i - X, p_i].
    #    For candidate 1, we need dp[j] - A*states[j].
    deq = deque()
    deq.append(0)
    # 2. A prefix minimum array for candidate 2: prefix[i] = min_{j=0..i} (dp[j] - B*states[j]).
    prefix = [0] * M
    prefix[0] = dp[0] - B * states[0]  # = 0.

    # Process states in increasing order.
    for i in range(1, M):
        pos = states[i]
        # Candidate 1 is valid for j with states[j] in [pos - X, pos].
        L_index = bisect_left(states, pos - X)
        # Remove indices from deque that are no longer in the window.
        while deq and deq[0] < L_index:
            deq.popleft()
        cand1 = INF
        if deq:
            # Candidate 1: dp[j] + (pos - states[j]) * A = A*pos + (dp[j] - A*states[j])
            cand1 = A * pos + (dp[deq[0]] - A * states[deq[0]])

        # Candidate 2: for j with states[j] < pos - X (so that d > X).
        cand2 = INF
        if L_index > 0:
            # For such j, cost = dp[j] + X*A + (pos - states[j] - X)*B
            #   = (dp[j] - B*states[j]) + B*pos + (X*A - X*B).
            cand2 = B * pos + (X * A - X * B) + prefix[L_index - 1]

        best = cand1 if cand1 < cand2 else cand2
        # If this state is a refill station (i.e. not the finish) add refill time.
        if pos != D:
            best += Yticks
        dp[i] = best

        # Update deque for candidate 1.
        curr_val = dp[i] - A * pos
        while deq and (dp[deq[-1]] - A * states[deq[-1]]) > curr_val:
            deq.pop()
        deq.append(i)

        # Update prefix minimum for candidate 2.
        prefix[i] = prefix[i - 1]
        cand_here = dp[i] - B * pos
        if cand_here < prefix[i]:
            prefix[i] = cand_here

    # dp[M-1] is the total time in ticks; convert back to seconds.
    result_sec = dp[-1] // L  # these divisions are exact.
    hh = result_sec // 3600
    mm = (result_sec % 3600) // 60
    ss = result_sec % 60
    sys.stdout.write(f"{hh:02d}:{mm:02d}:{ss:02d}")


if __name__ == "__main__":
    solve()
