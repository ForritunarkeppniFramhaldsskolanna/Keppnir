#!/usr/bin/python3

card_to_ord, suit, value = dict(), dict(), dict()

all_cards = []
lows = dict()
for (i, sort) in enumerate(["S", "B", "V", "M"]):
    for (j, val) in enumerate(["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "G", "R", "D", "K"]):
        lows[sort + val] = 4 * j + i
        card_to_ord[sort + val] = 4 * j + i + 1
        suit[sort + val] = sort
        value[sort + val] = j + 1
        all_cards.append(sort + val)

def make_row(hand):
    if len(set(hand)) != len(hand):
        return False
    ord_vals = [value[card] for card in hand]
    if len(set(ord_vals)) != len(ord_vals):
        return False
    return min(ord_vals) + len(hand) - 1 == max(ord_vals)

def prep_return(rank, pat, lft):
    pat_ord = sorted([card_to_ord[card] for card in pat], reverse=True)
    lft_ord = sorted([card_to_ord[card] for card in lft], reverse=True)
    return [rank] + pat_ord + lft_ord

def rank_hand(hand):
    values = [value[card] for card in hand]
    suits = [suit[card] for card in hand]
    vcounts = [values.count(values[i]) for i in range(5)]
    if len(set(values)) == 1:
        return prep_return(20, hand, [])
    if make_row(hand) and len(set(suits)) == 1:
        return prep_return(18, hand, [])
    if all([card[-1] in "GRDK" for card in hand]):
        return prep_return(13, hand, [])
    if len(set(values)) == 2 and sorted(vcounts) == [1, 4, 4, 4, 4]:
        ind = vcounts.index(1)
        return prep_return(12, [hand[j] for j in range(5) if j != ind], [hand[ind]])
    if len(set(values)) == 2: # Can't be 4, 1
        return prep_return(11, hand, [])
    if len(set(suits)) == 1:
        return prep_return(10, hand, [])
    if make_row(hand):
        return prep_return(9, hand, [])
    for i in range(5):
        if values.count(values[i]) == 3:
            return prep_return(5, [hand[j] for j in range(5) if values[j] == values[i]], [hand[j] for j in range(5) if values[i] != values[j]])
    if len(set(values)) == 3: # Not 3, 1, 1 so must be 2, 2, 1
        return prep_return(4, [hand[j] for j in range(5) if values.count(values[j]) == 2], [hand[j] for j in range(5) if values.count(values[j]) == 1])
    if len(set(values)) < 5:
        inds = [i for i in range(5) if values.count(values[i]) == 2]
        return prep_return(3, [hand[i] for i in inds], [hand[i] for i in range(5) if i not in inds])
    return prep_return(2, hand, [])

if __name__ == "__main__":
    konrad = rank_hand(list(input().strip().split()))
    atli = rank_hand(list(input().strip().split()))
    print(21 - konrad[0], 21 - atli[0])
    if konrad > atli:
        print("Konrad")
    elif atli > konrad:
        print("Atli")
    else:
        print("Jafntefli")
