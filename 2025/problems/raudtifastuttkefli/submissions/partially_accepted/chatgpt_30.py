def solve():
    import sys

    data = sys.stdin.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    k = int(next(it))
    videos = []
    for _ in range(n):
        L = int(next(it))
        D = int(next(it))
        videos.append((L, D))
    T = int(next(it))

    # dp is a dictionary mapping extra time x to maximum dopamine.
    # Initially, with 0 videos processed, x = 0 and dopamine = 0.
    dp = {0: 0}
    best = 0  # best dopamine found among states that are feasible

    # Process videos in order.
    for i, (L, D) in enumerate(videos):
        newdp = {}
        for x, dop in dp.items():
            # Option 1: Skip the video.
            new_x = x  # no change in extra time
            tot_time = (i + 1) * k + new_x
            if tot_time <= T:
                # update new state
                if new_x not in newdp or newdp[new_x] < dop:
                    newdp[new_x] = dop
                best = max(best, dop)
            # Option 2: Watch the video.
            new_x = x + (L - k)
            tot_time = (i + 1) * k + new_x
            if tot_time <= T:
                new_dop = dop + D
                if new_x not in newdp or newdp[new_x] < new_dop:
                    newdp[new_x] = new_dop
                best = max(best, new_dop)
        # Prune dominated states: sort by x and keep only states with strictly increasing dopamine.
        pruned = {}
        cur_max = -1
        for x_key in sorted(newdp.keys()):
            val = newdp[x_key]
            if val > cur_max:
                pruned[x_key] = val
                cur_max = val
        dp = pruned

    sys.stdout.write(str(best))


if __name__ == "__main__":
    solve()
