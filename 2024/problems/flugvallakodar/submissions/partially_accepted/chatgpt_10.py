#!/usr/bin/python3

def find_code(city, used_codes):
    city_upper = city.upper()
    for i in range(len(city_upper)):
        for j in range(i + 1, len(city_upper)):
            for k in range(j + 1, len(city_upper)):
                code = city_upper[i] + city_upper[j] + city_upper[k]
                if code not in used_codes:
                    return code
    return ":("

def main():
    n = int(input().strip())  # Read number of airports
    cities = [input().strip() for _ in range(n)]  # Read city names

    codes = []
    used_codes = set()

    for city in cities:
        if len(city) < 3:
            codes.append(":(")
            continue

        city_upper = city.upper()
        initial_code = city_upper[:3]

        if initial_code not in used_codes:
            code = initial_code
        else:
            code = find_code(city_upper, used_codes)

        codes.append(code)
        used_codes.add(code)

    # Output the codes
    for code in codes:
        print(code)

if __name__ == "__main__":
    main()

