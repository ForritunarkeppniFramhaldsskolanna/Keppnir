#!/usr/bin/python3
import sys

# Function to parse the rules from the input
def parse_rules(n):
    rule_sets = []
    for _ in range(n):
        num_rules = int(input())
        rules = [input() for _ in range(num_rules)]
        rule_sets.append(rules)
    return rule_sets

# Function to check if a password satisfies a rule
def satisfies_rule(password, rule):
    # This function will be implemented to handle different types of rules
    pass

# Function to generate passwords that satisfy at least one rule set
def generate_passwords(rule_sets, m):
    passwords = set()
    # This function will be implemented to generate passwords
    return passwords

def main():
    # Reading the number of rule sets and the number of passwords to generate
    n, m = map(int, input().split())

    # Parsing the rules
    rule_sets = parse_rules(n)

    # Generating passwords
    passwords = generate_passwords(rule_sets, m)

    # Outputting the results
    if passwords:
        print("Mogulegt!")
        for password in list(passwords)[:m]:
            print(password)
    else:
        print("Omogulegt!")

if __name__ == "__main__":
    main()

