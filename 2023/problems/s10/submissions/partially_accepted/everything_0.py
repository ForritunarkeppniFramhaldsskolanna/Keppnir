#!/usr/bin/python3
if __name__ == "__main__":
    n, k = map(int, input().split())

    registered = []
    for i in range(k):
        num_allocated_spots, num_registered_plates = map(int, input().split())
        for _ in range(num_registered_plates):
            plate = input()
            registered.append(plate)

    result = set()
    num_queries = int(input())

    for _ in range(num_queries):
        plate = input()
        result.add(plate)

    print(len(result))
    for plate in sorted(result):
        print(plate)
