#!/usr/bin/python3
from collections import defaultdict
import sys

def build_graph(n):
    graph = defaultdict(list)
    for _ in range(n):
        line = input().split()
        acronym, k = line[0], int(line[1])
        refs = line[2:]
        for ref in refs:
            if ref.isupper():  # Only consider other acronyms
                graph[acronym].append(ref)
    return graph

def calculate_complexity(graph, start, visited=None):
    if visited is None:
        visited = set()
    if start in visited:
        return 0
    visited.add(start)
    complexity = 1  # Include the acronym itself
    for neighbor in graph[start]:
        complexity += calculate_complexity(graph, neighbor, visited)
    return complexity

def main():
    n = int(input())  # Read number of acronyms
    graph = build_graph(n)
    complexities = [calculate_complexity(graph, acronym) for acronym in graph]
    for complexity in complexities:
        print(complexity)

if __name__ == "__main__":
    main()

