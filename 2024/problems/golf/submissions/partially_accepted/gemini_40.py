#!/usr/bin/python3
from collections import defaultdict


def main():
    n, q = map(int, input().split())
    players = input().split()
    scores = defaultdict(int)

    for _ in range(q):
        line = input().split()
        if line[0] == "!":
            k = int(line[1])
            for i in range(2, k + 2, 2):
                player = line[i]
                score = line[i + 1]
                scores[player] += int(score)
        else:
            player = line[1]
            rank = 1
            best_score = scores[player]
            for other_player, other_score in scores.items():
                if other_player != player and other_score < best_score:
                    rank += 1
            print(rank, scores[player])


if __name__ == "__main__":
    main()
