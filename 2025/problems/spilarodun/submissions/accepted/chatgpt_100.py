def main():
    import sys

    data = sys.stdin.read().strip().splitlines()
    if not data:
        return

    n = int(data[0])
    cards = []

    # Define the order for the main type and for the subtypes
    main_order = {"Skrimsli": 0, "Galdur": 1, "Gildra": 2, "Annad": 3}
    subtype_orders = {
        "Skrimsli": {
            "Venjulegt": 0,
            "Ahrifa": 1,
            "Bodunar": 2,
            "Samruna": 3,
            "Samstillt": 4,
            "Thaeo": 5,
            "Penduls": 6,
            "Tengis": 7,
        },
        "Galdur": {"Venjulegur": 0, "Bunadar": 1, "Svida": 2, "Samfelldur": 3, "Bodunar": 4, "Hradur": 5},
        "Gildra": {"Venjuleg": 0, "Samfelld": 1, "Mot": 2},
    }

    # Process each card line (next n lines)
    for i in range(1, n + 1):
        # Each line: name, ID, type, release date (comma-separated)
        parts = data[i].split(",")
        name = parts[0].strip()
        id_value = int(parts[1].strip())
        type_field = parts[2].strip()
        date = parts[3].strip()

        # Check if the type field includes a subtype (indicated by a dash)
        if "-" in type_field:
            type_main, subtype = [x.strip() for x in type_field.split("-", 1)]
            type_main_order = main_order[type_main]
            subtype_order = subtype_orders[type_main][subtype]
        else:
            type_main = type_field
            type_main_order = main_order[type_main]
            # For types that normally have subtypes this should not occur.
            # For "Annad" (which has no subtype) we set subtype order to 0.
            subtype_order = 0

        cards.append(
            {
                "name": name,
                "id": id_value,
                "date": date,
                "type_main_order": type_main_order,
                "type_sub_order": subtype_order,
            }
        )

    # The final line gives the sorting order
    sort_order = data[n + 1].split()

    # Build the sort key using the provided order.
    def sort_key(card):
        key = []
        for token in sort_order:
            if token == "nafn":
                key.append(card["name"])
            elif token == "id":
                key.append(card["id"])
            elif token == "dagsetning":
                key.append(card["date"])
            elif token == "flokkur":
                # For type we use a tuple (main type order, subtype order)
                key.append((card["type_main_order"], card["type_sub_order"]))
        return tuple(key)

    cards.sort(key=sort_key)

    # Output only the names of the cards in the sorted order.
    for card in cards:
        print(card["name"])


if __name__ == "__main__":
    main()
