#!/usr/bin/python3
def card_value(card):
    if len(card) > 1 and card[1].isdigit():  # Low cards with suits
        return (int(card[1:]), card[0])  # Value and suit
    elif card[0] in ['S', 'B', 'V', 'M']:  # Face cards
        values = {'G': 11, 'R': 12, 'D': 13, 'K': 14}
        return (values[card[1]], card[0])  # Value and suit for face cards

def evaluate_low_hand_corrected(cards):
    value_counts = {value: 0 for value in range(1, 15)}  # 1-10, G=11, R=12, D=13, K=14
    suit_counts = {'S': 0, 'B': 0, 'V': 0, 'M': 0}
    for value, suit in cards:
        value_counts[value] += 1
        suit_counts[suit] += 1

    flush_suit = None
    for suit, count in suit_counts.items():
        if count >= 5:
            flush_suit = suit
            break

    is_straight = False
    if flush_suit:
        sorted_flush_values = sorted(value for value, s in cards if s == flush_suit)
        for i in range(len(sorted_flush_values) - 4):
            if sorted_flush_values[i:i+5] == list(range(sorted_flush_values[i], sorted_flush_values[i] + 5)):
                is_straight = True
                break

    if is_straight and flush_suit:
        return 3
    if 4 in value_counts.values():
        return 9
    if sorted(value_counts.values(), reverse=True)[:2] == [3, 2]:
        return 10
    if flush_suit:
        return 11
    if 3 in value_counts.values():
        return 16
    if sorted(value_counts.values(), reverse=True)[:2] == [2, 2]:
        return 17
    if 2 in value_counts.values():
        return 18
    return 19

def analyze_and_determine_winner(konrad_cards, atli_cards):
    konrad_rank = evaluate_low_hand_corrected([card_value(card) for card in konrad_cards])
    atli_rank = evaluate_low_hand_corrected([card_value(card) for card in atli_cards])

    print(f"{konrad_rank} {atli_rank}")
    if konrad_rank < atli_rank:
        print("Konrad")
    elif konrad_rank > atli_rank:
        print("Atli")
    else:
        print("Jafntefli")

# Read input from standard input
konrad_cards_input = input().split()
atli_cards_input = input().split()

# Analyze hands and determine the winner
analyze_and_determine_winner(konrad_cards_input, atli_cards_input)

