#!/usr/bin/python3

def calculate_optimal_cost(n, m, k, movies):
    # Calculate the total cost if no cinema cards are used
    total_single_use_ticket_cost = sum(popularity * m for _, popularity in movies)
    
    # If the price of a single-use ticket is 0, buying cinema cards is unnecessary
    if m == 0:
        return 0, total_single_use_ticket_cost
    
    # Sort movies by popularity to prioritize movies with higher attendance for cinema card usage
    movies.sort(key=lambda x: x[1], reverse=True)
    
    # Initialize variables to track the best cost and number of cards
    best_cost = total_single_use_ticket_cost
    best_num_cards = 0
    
    # Try different numbers of cinema cards to find the optimal solution
    for cards in range(1, min(10**6, n) + 1):
        cost_with_cards = cards * k
        movies_left = n
        
        for _, popularity in movies:
            if movies_left <= 0:
                break
            # Calculate cost saving with a cinema card
            saving_per_movie = min(popularity, movies_left) * m
            cost_with_cards += max(0, (popularity - movies_left) * m)
            movies_left -= popularity
            
            if cost_with_cards >= best_cost:
                break
        
        if cost_with_cards < best_cost:
            best_cost = cost_with_cards
            best_num_cards = cards
    
    return best_num_cards, best_cost

def main():
    # Read the first line of input
    n, m, k = map(int, input().split())
    movies = []
    
    # Read each movie's details
    for _ in range(n):
        movie_input = input().split()
        movie_name = movie_input[0]
        popularity = int(movie_input[1])
        movies.append((movie_name, popularity))
    
    # Calculate and print the optimal number of cinema cards and total cost
    cards, cost = calculate_optimal_cost(n, m, k, movies)
    print(f"{cards} {cost}")

if __name__ == "__main__":
    main()

