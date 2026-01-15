import sys
import heapq


def solve():
    input_data = sys.stdin.read().strip().split()
    n = int(input_data[0])

    # Read assignments: each has (a_i, b_i, t_i)
    assignments = []
    idx = 1
    for _ in range(n):
        a = int(input_data[idx])
        b = int(input_data[idx + 1])
        t = int(input_data[idx + 2])
        idx += 3
        assignments.append((a, b, t))

    # Edge case: if n=0, answer is 0
    if n == 0:
        print(0)
        return

    # A trivial upper bound on X is the sum of all t_i
    # (because we could do all homework in 1 day if we had to).
    # Another possible upper bound is max(t_i), in case a single assignment must be done in one day (a_i == b_i).
    # But to be absolutely safe for all corner cases, we use sum(t_i).

    total_t = sum(t for (_, _, t) in assignments)
    max_t = max(t for (_, _, t) in assignments)
    upper_bound = max(total_t, max_t)

    # A trivial lower bound on X is 0, but obviously that might not be feasible if there's any t_i > 0.
    # We can start from 0 and let feasibility checks handle it.
    # lower_bound = 0

    # Precompute a sorted list of "event days" to compress the timeline:
    # We will consider day b_i inclusive, so the assignment expires right after day b_i => at day (b_i+1).
    # So each assignment i yields two key days: a_i (becomes active), b_i+1 (expires).
    # We'll do a line sweep across these sorted distinct days.

    # Build the set of all relevant days:
    day_set = set()
    for a, b, t in assignments:
        day_set.add(a)  # assignment i becomes available on day a
        day_set.add(b + 1)  # assignment i can no longer be done after day b

    # Remove any negative or weird day if problem states day≥0, but not strictly necessary.
    # Convert to sorted list:
    day_list = sorted(day_set)

    # Build "events": (day, type, i)
    # type = +1 => assignment i becomes active that day
    # type = -1 => assignment i expires that day (so after day-1 is the last chance)
    # We will process these events when we reach each "event day" in our sweep.
    events = []
    for i, (a, b, t) in enumerate(assignments):
        events.append((a, +1, i))
        events.append((b + 1, -1, i))
    # Sort events by day primarily; in a tie, we want +1 (activate) before -1 (expire).
    events.sort(key=lambda x: (x[0], -x[1]))

    # For convenience, store each assignment’s time requirement and "deadline" in arrays.
    # We'll interpret "deadline" as b_i + 1, i.e. the first day on which we can no longer do the task.
    remain = [t for (_, _, t) in assignments]
    deadline = [b + 1 for (_, b, _) in assignments]

    # We'll define a function feasible(X) that returns True if we can finish all tasks with daily capacity X.
    def can_finish_with(X):
        # Reset remain[] each time we test feasibility
        # (To avoid copying the entire remain array every time, we’ll store a separate array.)
        cur_remain = remain[:]

        # Min-heap for active tasks, keyed by actual deadline day (deadline[i])
        # We'll push (deadline[i], i) so that popping gets earliest deadline first.
        active_heap = []

        # We'll iterate over day_list in ascending order. Between day_list[j] and day_list[j+1] - 1,
        # we have (day_list[j+1] - day_list[j]) * X total capacity.
        # We'll keep an index over the events list to know which tasks become active / expire at each day_list[j].
        e_idx = 0
        n_events = len(events)

        # Process each consecutive pair of days in day_list
        for j in range(len(day_list) - 1):
            d_start = day_list[j]
            d_end = day_list[j + 1] - 1
            # The number of actual days in [d_start, d_end] is:
            delta = d_end - d_start + 1
            if delta < 0:
                delta = 0  # no actual gap here

            # First, handle all events that occur exactly at d_start
            #   - If type=+1 => add that task to the heap
            #   - If type=-1 => if that task still has remain>0, fail, else remove from consideration
            while e_idx < n_events and events[e_idx][0] == d_start:
                _, evtype, i_task = events[e_idx]
                if evtype == +1:
                    # Task i_task becomes available => push it in the heap
                    heapq.heappush(active_heap, (deadline[i_task], i_task))
                else:
                    # evtype == -1 => that means day = b_i+1 => we are no longer allowed to do it
                    # if remain is not zero => fail immediately
                    if cur_remain[i_task] > 0:
                        return False
                    # If it’s already done, we just ignore it.
                e_idx += 1

            # Now we have delta * X capacity to spend on active tasks
            # in earliest deadline order. So we pop from the heap.
            capacity = delta * X

            while capacity > 0 and active_heap:
                (ddl, i_task) = heapq.heappop(active_heap)

                # If this task’s deadline is <= d_start, we are already late
                # (deadline[i_task] = b_i+1, so if b_i+1 <= d_start => we missed finishing by day b_i).
                if ddl <= d_start:
                    return False

                # We can allocate min(capacity, cur_remain[i_task]) units to this task
                needed = cur_remain[i_task]
                use = min(capacity, needed)
                cur_remain[i_task] -= use
                capacity -= use

                # If the task is not yet done, push it back with the same deadline
                if cur_remain[i_task] > 0:
                    heapq.heappush(active_heap, (ddl, i_task))

            # Done allocating for this day-interval; move on.

        # We have processed all intervals except possibly events at the final day_list[-1].
        # One last pass to handle events at day_list[-1]:
        final_day = day_list[-1]
        while e_idx < n_events and events[e_idx][0] == final_day:
            _, evtype, i_task = events[e_idx]
            if evtype == +1:
                heapq.heappush(active_heap, (deadline[i_task], i_task))
            else:
                # if remain>0 => fail
                if cur_remain[i_task] > 0:
                    return False
            e_idx += 1

        # After day_list[-1], we have no more days left to work (no further intervals).
        # Any task still incomplete in active_heap would require time after day_list[-1],
        # so if a task’s deadline is <= day_list[-1], we are late. If remain>0 for any, we fail.
        while active_heap:
            ddl, i_task = heapq.heappop(active_heap)
            if cur_remain[i_task] > 0:
                # We have no more capacity beyond day_list[-1]
                return False

        # If we never failed, it’s feasible
        return True

    # Now do a standard binary search for the smallest X in [0 .. upper_bound]
    lo, hi = 0, upper_bound
    ans = upper_bound  # we will store the best feasible

    while lo <= hi:
        mid = (lo + hi) // 2
        if can_finish_with(mid):
            ans = mid
            hi = mid - 1
        else:
            lo = mid + 1

    print(ans)


solve()
