#!/usr/bin/python3

card_to_ord, suit, value, parallel_value = dict(), dict(), dict(), dict()
card_to_ord["J"] = 0
suit["J"] = None
value["J"] = None
parallel_value["J"] = None

high_cards = ["O", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI"]
highs = dict()
for i in range(len(high_cards)):
    highs[high_cards[i]] = i
    card_to_ord[high_cards[i]] = 57 + i
    suit[high_cards[i]] = None
    value[high_cards[i]] = i + 15
    parallel_value[high_cards[i]] = i

all_cards = high_cards[:]
lows = dict()
for (i, sort) in enumerate(["B", "S", "V", "M"]):
    for (j, val) in enumerate(["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "G", "R", "D", "K"]):
        lows[sort + val] = 4 * j + i
        card_to_ord[sort + val] = 4 * j + i + 1
        suit[sort + val] = sort
        value[sort + val] = j + 1
        if val in "GRDK":
            parallel_value[sort + val] = None
        else:
            parallel_value[sort + val] = j + 1
        all_cards.append(sort + val)

def make_row(hand):
    if len(set(hand)) != len(hand):
        return False
    ord_vals = [value[card] for card in hand]
    if len(set(ord_vals)) != len(ord_vals):
        return False
    if min(ord_vals) < 15 and max(ord_vals) >= 15:
        return False
    return min(ord_vals) + len(hand) - 1 == max(ord_vals)

def prep_return(rank, pat, lft):
    pat_ord = sorted([card_to_ord[card] for card in pat], reverse=True)
    lft_ord = sorted([card_to_ord[card] for card in lft], reverse=True)
    return [rank] + pat_ord + lft_ord

def rank_hand(hand):
    values = [value[card] for card in hand]
    lows_para = [parallel_value[card] for card in hand if card in lows]
    high_para = [parallel_value[card] for card in hand if card in highs]
    suits = [suit[card] for card in hand]
    lows_vals = [value[card] for card in hand if card in lows]
    high_vals = [value[card] for card in hand if card in highs]
    vcounts = [values.count(values[i]) for i in range(5)]
    if len(set(values)) == 1:
        return prep_return(20, hand, [])
    if len(lows_vals) == 0:
        return prep_return(19, hand, [])
    if len(high_vals) == 0 and make_row(hand) and len(set(suits)) == 1:
        return prep_return(18, hand, [])
    if len(set(suits)) == 5:
        return prep_return(17, hand, [])
    if len(high_vals) == 1 and len(lows_vals) == 4 and None not in lows_para and sum(lows_para) == sum(high_para):
        return prep_return(16, hand, [])
    if len(high_vals) == 1 and len(set(lows_vals)) == 1 and lows_para[0] == high_para[0]:
        return prep_return(15, hand, [])
    if len(lows_para) >= 3 and len(high_para) >= 1:
        mn, ind = 1000, -1
        for i in range(5):
            new_lows_para = [parallel_value[hand[j]] for j in range(5) if j != i and hand[j] in lows]
            new_high_para = [parallel_value[hand[j]] for j in range(5) if j != i and hand[j] in highs]
            if None in new_lows_para or len(new_lows_para) != 3 or len(new_high_para) != 1:
                continue
            if sum(new_lows_para) != sum(new_high_para):
                continue
            x = card_to_ord[hand[i]]
            if x < mn:
                mn = x
                ind = i
        if mn != 1000:
            return prep_return(14, [hand[i] for i in range(5) if i != ind], [hand[ind]])
    if all([card[-1] in "GRDK" for card in hand]):
        return prep_return(13, hand, [])
    if len(set(values)) == 2 and sorted(vcounts) == [1, 4, 4, 4, 4]:
        ind = vcounts.index(1)
        return prep_return(12, [hand[j] for j in range(5) if j != ind], [hand[ind]])
    if len(set(values)) == 2: # Can't be 4, 1
        return prep_return(11, hand, [])
    if None not in suits and len(set(suits)) == 1:
        return prep_return(10, hand, [])
    if make_row(hand):
        return prep_return(9, hand, [])
    if len(high_vals) >= 2 and len(lows_vals) >= 2:
        for i in range(5):
            if len(high_vals) - (1 if hand[i] in highs else 0) != 2:
                continue
            new_lows_para = [parallel_value[hand[j]] for j in range(5) if j != i and hand[j] in lows]
            new_high_para = sorted([parallel_value[hand[j]] for j in range(5) if j != i and hand[j] in highs])
            if None in new_lows_para:
                continue
            new_lows_para.sort()
            if new_lows_para == new_high_para:
                return prep_return(8, [hand[j] for j in range(5) if j != i], [hand[i]])
    if len(high_vals) >= 1 and len(lows_vals) >= 1:
        mn, ind = 1000, -1
        for i in range(5):
            new_lows_para = [parallel_value[hand[j]] for j in range(5) if j != i and hand[j] in lows]
            new_high_para = sorted([parallel_value[hand[j]] for j in range(5) if j != i and hand[j] in highs])
            if len(new_lows_para) not in [1, 3]:
                continue
            if len(new_high_para) not in [1, 3]:
                continue
            if len(new_high_para) == len(new_lows_para):
                continue
            if len(new_high_para) == 3:
                if new_lows_para[0] not in new_high_para:
                    continue
                del new_high_para[new_high_para.index(new_lows_para[0])]
                if len(set(new_high_para)) != 1:
                    continue
            else:
                if new_high_para[0] not in new_lows_para:
                    continue
                del new_lows_para[new_lows_para.index(new_high_para[0])]
                if len(set(new_lows_para)) != 1:
                    continue
            x = card_to_ord[hand[i]]
            if x < mn:
                mn = x
                ind = i
        if mn != 1000:
            return prep_return(7, [hand[j] for j in range(5) if j != ind], [hand[ind]])
    if len(high_vals) >= 1 and len(lows_vals) >= 1: # must make sure to pick maximum corresp.
        mx, ind = -1, -1
        for i in range(5): # unique i because no 2 high pair
            if hand[i] not in highs:
                continue
            if parallel_value[hand[i]] not in lows_para:
                continue
            for j in range(5):
                if hand[j] not in lows:
                    continue
                if parallel_value[hand[i]] != parallel_value[hand[j]]:
                    continue
                x = card_to_ord[hand[j]]
                if x > mx:
                    mx = x
                    ind = (i, j)
        if mx != -1:
            return prep_return(6, [hand[j] for j in ind], [hand[j] for j in range(5) if j not in ind])
    for i in range(5):
        if values.count(values[i]) == 3:
            return prep_return(5, [hand[j] for j in range(5) if values[j] == values[i]], [hand[j] for j in range(5) if values[i] != values[j]])
    if len(set(values)) == 3: # Not 3, 1, 1 so must be 2, 2, 1
        return prep_return(4, [hand[j] for j in range(5) if values.count(values[j]) == 2], [hand[j] for j in range(5) if values.count(values[j]) == 1])
    if len(set(values)) < 5:
        inds = [i for i in range(5) if values.count(values[i]) == 2]
        return prep_return(3, [hand[i] for i in inds], [hand[i] for i in range(5) if i not in inds])
    if len(high_vals) == 0:
        return prep_return(2, hand, [])
    return prep_return(1, hand, [])

def max_joker_rank(hand):
    j_cnt = hand.count("J")
    if j_cnt == 0:
        return rank_hand(hand)
    if j_cnt == 5:
        return rank_hand(["XXI", "XXI", "XXI", "XXI", "XXI"])
    left = [card for card in hand if card != "J"]
    if j_cnt == 4:
        if left[0] in highs:
            return rank_hand([left[0] for j in range(5)])
        else:
            best = "M" + left[0][1:]
            return rank_hand(left + [best for j in range(4)])
    if j_cnt == 3: # Too slow for triple loop, C++ might get away with it though
        if value[left[0]] == value[left[1]]: # Go for 5 same
            if left[0] in highs:
                return rank_hand([left[0] for j in range(5)])
            else:
                best = "M" + left[0][1:]
                return rank_hand(left + [best for j in range(3)])
        elif left[0] in highs and left[1] in highs: # Go for all highs
            return rank_hand(left + ["XXI", "XXI", "XXI"])
        elif suit[left[0]] is not None and suit[left[0]] == suit[left[1]] and abs(value[left[0]] - value[left[1]]) <= 4: # Go for colour flush
            cur_suit = left[0][0]
            def val2str(k):
                nam = str(k)
                if nam == "11": 
                    nam = "G"
                if nam == "12": 
                    nam = "R"
                if nam == "13": 
                    nam = "D"
                if nam == "14": 
                    nam = "K"
                return nam
            mn = min(value[left[0]], value[left[1]])
            mx = max(value[left[0]], value[left[1]])
            for k in range(mn + 1, mx):
                left.append(cur_suit + val2str(k))
            for k in range(mx + 1, 15):
                if len(left) == 5:
                    break
                left.append(cur_suit + val2str(k))
            for k in range(mn - 1, 0, -1):
                if len(left) == 5:
                    break
                left.append(cur_suit + val2str(k))
            return rank_hand(left)
        elif (left[0] in highs or left[1] in highs) or (suit[left[0]] != suit[left[1]]): # Go for diversity, can't have both high
            suits_left = set(["S", "B", "V", "M"])
            if suit[left[0]] is not None:
                suits_left.remove(suit[left[0]])
            if suit[left[1]] is not None:
                suits_left.remove(suit[left[1]])
            for cur_suit in suits_left:
                left.append(cur_suit + "K")
            if len(left) != 5:
                left.append("XXI")
            return rank_hand(left)
        else: # Both must be low and can't have sum 20 since 10, 10 would be first case
            v1, v2 = 1, 1
            for i in range(19 - parallel_value[left[0]] - parallel_value[left[1]]):
                if v1 == 10:
                    v2 += 1
                else:
                    v1 += 1
            return rank_hand(left + ["M" + str(v1), "M" + str(v2), "XXI"])
    mx = [-1, -1, -1, -1, -1, -1]
    if j_cnt == 1:
        for i in range(len(all_cards)):
            mx = max(mx, rank_hand(left + [all_cards[i]]))
    if j_cnt == 2:
        for i in range(len(all_cards)):
            for j in range(i, len(all_cards)):
                mx = max(mx, rank_hand(left + [all_cards[i], all_cards[j]]))
    return mx

if __name__ == "__main__":
    konrad = max_joker_rank(list(input().strip().split()))
    atli = max_joker_rank(list(input().strip().split()))
    print(21 - konrad[0], 21 - atli[0])
    if konrad > atli:
        print("Konrad")
    elif atli > konrad:
        print("Atli")
    else:
        print("Jafntefli")
