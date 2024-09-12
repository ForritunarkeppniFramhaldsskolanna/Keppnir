#!/usr/bin/python3

def find_best_performance(n, k, p, component_types, components):
    # Organize components by type
    components_by_type = {component_type: [] for component_type in component_types}
    for component in components:
        type_, price, performance = component
        components_by_type[type_].append((price, performance))

    # For each component type, sort components by price (ascending)
    for type_ in components_by_type:
        components_by_type[type_].sort(key=lambda x: x[0])

    # Dynamic programming approach to find the best performance within budget
    # dp[i][j] = maximum performance with i types considered and a budget of j
    dp = [[0 for _ in range(p + 1)] for _ in range(k + 1)]

    # Initialize dp for the first component type
    for price, performance in components_by_type[component_types[0]]:
        for budget in range(price, p + 1):
            dp[1][budget] = max(dp[1][budget], performance)

    # Update dp table for each component type
    for i in range(2, k + 1):
        for budget in range(p + 1):
            for price, performance in components_by_type[component_types[i - 1]]:
                if budget >= price:
                    dp[i][budget] = max(dp[i][budget], min(dp[i - 1][budget - price], performance))

    # Find the best performance achievable with the given budget
    best_performance = max(dp[k])

    return best_performance if best_performance > 0 else "O nei!"

def main():

    # Reading input similar to stdin

    n, k, p = map(int, input().split())

    component_types = input().split()

    components = [input().split() for _ in range(n)]

    components = [(x[0], int(x[1]), int(x[2])) for x in components]



    # Process the components to find the best performance

    best_performance = find_best_performance(n, k, p, component_types, components)



    # Printing output similar to stdout

    print(best_performance)

