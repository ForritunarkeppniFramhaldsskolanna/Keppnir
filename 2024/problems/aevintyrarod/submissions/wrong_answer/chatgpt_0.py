#!/usr/bin/python3
def sort_quests(n, x, quests):
    # Sort quests based on the reward they offer (ax + b), in descending order
    sorted_quests = sorted(quests, key=lambda quest: quest[1] * x + quest[2], reverse=True)
    
    # Return the names of the quests in the sorted order
    return [quest[0] for quest in sorted_quests]

def main():
    # Read the first line of input for the number of quests and initial experience points
    n, x = map(int, input().strip().split())

    # Initialize a list to store the quests
    quests = []

    # Read each quest's details from the input
    for _ in range(n):
        quest_input = input().strip().split()
        quest_name = quest_input[0]
        a, b = int(quest_input[1]), int(quest_input[2])
        quests.append((quest_name, a, b))

    # Process the quests to find the optimal order
    optimal_order = sort_quests(n, x, quests)

    # Print the quest names in the optimal order
    for quest_name in optimal_order:
        print(quest_name)

if __name__ == "__main__":
    main()

