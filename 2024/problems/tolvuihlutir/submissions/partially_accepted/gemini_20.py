#!/usr/bin/python3
def best_computer(n, k, budget, components):
    component_sets = {}  # Store components by type

    # Parse components into a dictionary
    for component in components:
        t, cost, performance = component.split()
        cost, performance = int(cost), int(performance)
        component_sets.setdefault(t, []).append((cost, performance))

    # Sort components in each category by price
    for component_type in component_sets:
        component_sets[component_type].sort()

    # Simulate purchase, prioritizing cheapest components first
    chosen_components = []
    for component_type in component_sets:
        for cost, performance in component_sets[component_type]:
            if cost <= budget:
                budget -= cost
                chosen_components.append(performance)
                break  # Purchase only one per category

    # Check if we built a complete computer and output
    if len(chosen_components) == k:
        print(min(chosen_components))
    else:
        print("O nei!")


# Get input (modify depending on your input source)
n, k, budget = map(int, input().split())
component_types = input().split()
components = []
for _ in range(n):
    components.append(input())

best_computer(n, k, budget, components)
