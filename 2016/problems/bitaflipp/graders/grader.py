GROUP_SCORES = [25, 25, 50]
GROUP_CASES = [[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15], [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31], [0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31]]
import sys

def main():
    if "ignore" in sys.argv:
        print "AC 0"
    elif "groups" in sys.argv:
        verdicts = []
        scores = []
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            verdicts.append(verdict)
            scores.append(score if verdict == "AC" else 0)
        total_score = 0
        first_error = None
        for group in range(len(GROUP_SCORES)):
            group_score = GROUP_SCORES[group]
            for case in GROUP_CASES[group]:
                if scores[case] == 0:
                    group_score = 0
                if verdicts[case] != "AC" and not first_error:
                    first_error = verdicts[case]
            total_score += group_score
        if total_score == 0 and first_error:
            print "%s 0" % first_error
        else:
            print "AC %f" % total_score
    elif "sum" in sys.argv:
        total_score = 0
        first_error = None
        for line in sys.stdin.readlines():
            verdict, score = line.split()
            total_score += float(score)
            if verdict != "AC" and not first_error:
                first_error = verdict
        if total_score == 0 and first_error:
            print "%s 0" % first_error
        else:
            print "AC %f" % total_score
    else:
        for line in sys.stdin.readlines():
            print line

main()

