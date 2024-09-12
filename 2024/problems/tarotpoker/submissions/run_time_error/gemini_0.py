#!/usr/bin/python3
def is_comparable(high_card, low_card):
    if not high_card.isalnum() or not low_card.isalnum():
        return False  # Only compare numerical cards
    return int(high_card) == int(low_card[:-1]) or int(high_card) == 15  # Check for XV


def evaluate_hand(cards):
    num_jokers = cards.count("J")

    def try_joker_assignments(cards, remaining_jokers):
        best_rank = 20  # Start with the worst possible rank

        if remaining_jokers == 0:
            return evaluate_best_hand(cards)

        for i in range(len(cards)):
            if cards[i] != 'J':
                for possible_card in all_possible_values:
                    new_cards = cards[:]
                    new_cards[i] = possible_card
                    result = try_joker_assignments(new_cards, remaining_jokers - 1)
                    best_rank = min(best_rank, result)  # Update if better

        return best_rank

    all_possible_values = [str(x) for x in range(0, 22)] + ['S1', 'S2', 'S3', 'S4', 'S5', 'S6', 'S7', 'S8', 'S9', 'S10', 'SG', 'SR', 'SD', 'SK',
                                                        'V1', 'V2', 'V3', 'V4', 'V5', 'V6', 'V7', 'V8', 'V9', 'V10', 'VG', 'VR', 'VD', 'VK',
                                                        'M1', 'M2', 'M3', 'M4', 'M5', 'M6', 'M7', 'M8', 'M9', 'M10', 'MG', 'MR', 'MD', 'MK',
                                                        'B1', 'B2', 'B3', 'B4', 'B5', 'B6', 'B7', 'B8', 'B9', 'B10', 'BG', 'BR', 'BD', 'BK']

    return try_joker_assignments(cards, num_jokers)


def evaluate_best_hand(cards):
    # Group cards by value (excluding jokers)
    value_counts = {card: cards.count(card) for card in cards if card != "J"}

    # Check for five of a kind
    for value, count in value_counts.items():
        if count + cards.count("J") >= 5:
            return 1

    # Check for no lows
    if all(card in ["J"] + [str(x) for x in range(0, 22)] for card in cards):
        return 2

    # Check for Straight Flush
    suits = set([card[:-1] for card in cards if card != "J"])
    if len(suits) == 1:
        unique_values = sorted(set(int(card) for card in cards if card != "J"))
        possible_values = unique_values + [
            x for x in range(unique_values[0] - 4, unique_values[-1] + 5)
        ]

        for i in range(len(possible_values) - 4):
            straight_cards = possible_values[i:i + 5]
            missing_cards = sum(
                card not in cards and card != "J" for card in straight_cards
            )
            if missing_cards > 1:
                continue
            if all(str(card) in cards for card in straight_cards) or all(
                card in cards for card in straight_cards if card != "J"
            ):
                return 3

    # Check for Diversity
    suits = set([card[:-1] for card in cards])
    low_cards = [
        card for card in cards if card[-1] in ["G", "R", "D", "K"]
    ]  # Filter for low cards
    if (
        len(suits) == 4 and len(low_cards) == 4 and "J" not in cards
    ):  # 4 suits, 4 low cards, no jokers
        high_card_value = max(
            int(card) for card in cards if card.isalnum()
        )  # Find the highest high card
        if high_card_value <= 21:
            return 4  # Diversity!

    # Check for Houses
    value_counts = {
        card: cards.count(card) for card in cards
    }  # Include jokers this time

    for value, count in value_counts.items():
        if count >= 3:  # Potential three-of-a-kind
            remaining_cards = [card for card in cards if card != value]
            pairs = [
                card
                for card in set(remaining_cards)
                if remaining_cards.count(card) >= 2
            ]

            if pairs:  # We have a potential pair
                if all(is_comparable(value, pair) for pair in pairs):
                    return 5  # Comparable House (all pairs are comparable)
                elif value.isalnum() and sum(
                    int(pair[:-1]) for pair in pairs if pair.isalnum()
                ) == int(value):
                    return 6  # Sum House
                else:
                    return 10  # Full House (non-comparable)

    # Check for Numberless
    if all(card[-1] in ["G", "R", "D", "K"] for card in cards):
        return 8  # Numberless!

    # Check for Flush
    suits = set([card[:-1] for card in cards])
    if len(suits) == 1:
        return 11

    # Check for Straight
    values = sorted(set([int(card) for card in cards if card.isalnum()]))
    possible_values = values + [x for x in range(values[0] - 4, values[-1] + 5)]
    for i in range(len(possible_values) - 4):
        if all(str(x) in cards for x in possible_values[i:i + 5]):
            return 12

    # Check for Pairs, Three of a Kind, etc.
    value_counts = {card: cards.count(card) for card in cards}

    # Three of a Kind
    if 3 in value_counts.values():
        return 17

    # Two Pairs
    if list(value_counts.values()).count(2) == 2:
        return 18

    # One Pair
    if 2 in value_counts.values():
        return 19

    # No Highs (Default)
    if all(card.islower() for card in cards):
        return 20

    # Highest Card (Even worse default)
    return 21

    return 20  # Default: Highest Card


def get_input():
    konrad_hand = input().split()
    atli_hand = input().split()
    return konrad_hand, atli_hand


def print_winner(konrad_rank, atli_rank):
    if konrad_rank < atli_rank:
        print("Konrad")
    elif atli_rank < konrad_rank:
        print("Atli")
    else:
        print("Jafntefli")


# Main execution
konrad_hand, atli_hand = get_input()
konrad_rank = evaluate_hand(konrad_hand)
atli_rank = evaluate_hand(atli_hand)
print(konrad_rank, atli_rank)
print_winner(konrad_rank, atli_rank)
