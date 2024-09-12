#!/usr/bin/python3
def arrange_staff(staff_list):
    arranged_staff = []
    arranged_staff.append(staff_list[0])  # Add the non-relative first
    relatives = True  # Flag to alternate

    for i in range(1, len(staff_list)):
        if relatives:
            arranged_staff.append(staff_list[i])
            relatives = False
        else:
            arranged_staff.insert(1, staff_list[i])  # Insert at second position
            relatives = True

    return arranged_staff


def main():
    n = int(input())  # Read the number of staff members
    staff_members = []

    for _ in range(n):
        staff_members.append(input())  # Read each staff member's name

    fair_order = arrange_staff(staff_members)

    # Print the fair arrangement
    for name in fair_order:
        print(name)


if __name__ == "__main__":
    main()
