import sys

def is_int(arg):
    try:
        int(arg)
        return True
    except:
        return False

# Seven groups:
# 1: N <= 1000, Q <= 1000, guaranteed path (10 points)
# 2: N <= 1000, Q <= 1000 (20 points)
# 3: N <= 7000, Q <= 120000, guaranteed path (10 points)
# 4: N <= 7000, Q <= 120000 (10 points)
# 5: N <= 50000, Q <= 70000, guaranteed path, nicer cases (10 points)
# 6: N <= 50000, Q <= 70000, guaranteed path (30 points)
# 7: N <= 50000, Q <= 70000 (10 points)

# $ ls ../data/secret/*.in | sort
# ../data/secret/1a-1234567.in
# ../data/secret/1b-1234567.in
# ../data/secret/1c-1234567.in
# ../data/secret/1d-1234567.in
# ../data/secret/2a-247.in
# ../data/secret/3a-34567.in
# ../data/secret/3b-34.in
# ../data/secret/3c-34.in
# ../data/secret/3d-34.in
# ../data/secret/3e-34.in
# ../data/secret/4a-47.in
# ../data/secret/5a-567.in
# ../data/secret/5b-567.in
# ../data/secret/5c-67.in
# ../data/secret/5d-67.in
# ../data/secret/7a-7.in

TEST_CASE_IN_GROUP = [
        [1, 2, 3, 4, 5, 6, 7],
        [1, 2, 3, 4, 5, 6, 7],
        [1, 2, 3, 4, 5, 6, 7],
        [1, 2, 3, 4, 5, 6, 7],
        [   2,    4,       7],
        [      3, 4,        ],
        [      3, 4,        ],
        [      3, 4,        ],
        [      3, 4,        ],
        [      3, 4,        ],
        [         4,       7],
        [            5, 6, 7],
        [            5, 6, 7],
        [               6, 7],
        [               6, 7],
        [                  7]]

GROUP_NEEDS_TEST_CASES = [[]] # Yes, 1-indexed. Sorry about that.
for i in xrange(1, 8):
        reqs = []
        for j in xrange(len(TEST_CASE_IN_GROUP)):
                if i in TEST_CASE_IN_GROUP[j]:
                        reqs.append(j)
        GROUP_NEEDS_TEST_CASES.append(reqs)

GROUP_SCORE = [-1, 10, 20, 10, 10, 10, 30, 10]

def main():
    if "ignore" in sys.argv:
        print "AC 0"
    elif "sum" in sys.argv:
        error = None
        total_score = 0
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            if verdict != "AC":
                if not error:
                    error = verdict
            total_score += float(score)
        if not total_score and error:
            print "%s 0" % error
        else:
            print "AC %f" % total_score
    elif "all" in sys.argv:
        error = None
        current_test_case_index = 0
        test_case_results = [False] * len(TEST_CASE_IN_GROUP)
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            if verdict != "AC":
                if not error:
                    error = verdict
            else:
                test_case_results[current_test_case_index] = True
            current_test_case_index += 1

        total_score = 0
        # Loop through the groups
        for i in xrange(1, 8):
                ok = True
                # Check that every test case is accepted in this group
                for tc in GROUP_NEEDS_TEST_CASES[i]:
                        if not test_case_results[tc]:
                                ok = False
                if ok:
                        total_score += GROUP_SCORE[i]

        if not total_score and error:
            print "%s 0" % error
        else:
            print "AC %f" % total_score
    else:
        for line in sys.stdin.readlines():
            print line

main()
