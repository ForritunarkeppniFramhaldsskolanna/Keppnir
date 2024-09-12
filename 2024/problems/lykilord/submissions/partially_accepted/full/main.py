#!/usr/bin/env python3
import random
import sys
sys.dont_write_bytecode = True

from itertools import repeat
from functools import lru_cache

from dfa import DFA
from exceptions import InfiniteLanguageException

LIMIT = 32

alphabet = {chr(i) for i in range(33, 127)}

if __name__ == "__main__":
    words = None
    passwords = None

    def load_words():
        global words
        if words is None:
            with open("words.txt") as f:
                words = [line.rstrip('\n') for line in f.readlines()]

    def load_passwords():
        global passwords
        if passwords is None:
            with open("passwords.txt") as f:
                passwords = [line.rstrip('\n') for line in f.readlines()]

    def get_common(count):
        global passwords
        load_passwords()
        return DFA.from_finite_language(alphabet, passwords[:count], as_partial=False)

    def consecutive(count, step=0):
        substrings = set()
        for initial_symbol in alphabet:
            cur_symbol = initial_symbol
            substring = []
            while cur_symbol in alphabet and len(substring) < count:
                substring.append(cur_symbol)
                cur_symbol = chr(ord(cur_symbol) + step)
            if len(substring) == count:
                substrings.add(''.join(substring))
        return DFA.from_substrings(alphabet, substrings)

    def contain_english():
        global words
        load_words()
        return DFA.from_substrings(alphabet, words)

    def be_english():
        global words
        load_words()
        return DFA.from_finite_language(alphabet, words, as_partial=False)

    @lru_cache(maxsize=None)
    def parse_rule(line):
        rule = line.split()
        if rule[0] == "not":
            return parse_rule(' '.join(rule[1:])).complement(minify=False)
        if rule[0] == "contain":
            if rule[1] == "at":
                if rule[2] == "least":
                    value = int(rule[3])
                    if len(rule) == 5:
                        return DFA.of_length(alphabet, min_length=value)
                    else:
                        charset = ' '.join(rule[6:])
                        return DFA.of_length(alphabet, min_length=value, symbols_to_count=set(charset))
                        
                elif rule[2] == "most":
                    value = int(rule[3])
                    if len(rule) == 5:
                        return DFA.of_length(alphabet, max_length=value)
                    else:
                        charset = ' '.join(rule[6:])
                        return DFA.of_length(alphabet, max_length=value, symbols_to_count=set(charset))
            if rule[1] == "an":
                return contain_english()
            if rule[2] == "consecutive":
                if rule[3] == "equal":
                    return consecutive(int(rule[1]))
                if rule[3] == "incrementing":
                    return consecutive(int(rule[1]), step=1)
                if rule[3] == "decrementing":
                    return consecutive(int(rule[1]), step=-1)
        if rule[0] == "include":
            return DFA.from_substring(alphabet, rule[1])
        if rule[0] == "start":
            return DFA.from_prefix(alphabet, ' '.join(rule[2:]))
        if rule[0] == "end":
            return DFA.from_suffix(alphabet, ' '.join(rule[2:]))
        if rule[0] == "be":
            if rule[1] == "an":
                return be_english()
            if rule[1] == "in":
                return get_common(int(rule[3]))
        raise NotImplementedError

    def print_stats(dfa):
        print(f"States: {len(dfa.states)}")
        try:
            print(f"Cardinality: {dfa.cardinality()}")
        except InfiniteLanguageException:
            print(f"Cardinality: inf")
        print()


    n, m = map(int, sys.stdin.readline().split())
    dfa = DFA.empty_language(alphabet) if n > 0 else DFA.of_length(alphabet, max_length=LIMIT)
    rules = []

    for i in range(n):
        k = int(input())
        current_rules = set()
        for j in range(k):
            line = sys.stdin.readline().rstrip('\n')
            current_rules.add(line)
        rules.append(current_rules)

    common = None
    for r in rules:
        common = common & r if common is not None else r
    if common is None:
        common = set()

    common_dfa = DFA.of_length(alphabet, max_length=LIMIT)
    for rule in common:
        common_dfa = common_dfa & parse_rule(rule)

    for i, r in enumerate(rules):
        sub_dfa = DFA.of_length(alphabet, max_length=LIMIT)
        for rule in (r - common):
            sub_dfa = sub_dfa & parse_rule(rule)
        dfa = dfa.union(sub_dfa)

    dfa = dfa & common_dfa

    if len(sys.argv) > 1 and sys.argv[1] == "cardinality":
        if dfa.isfinite():
            sys.stdout.write(f"{dfa.cardinality()}\n")
        else:
            sys.stdout.write("inf\n")
    elif dfa.isfinite() and dfa.cardinality() < m:
        sys.stdout.write("Omogulegt!\n")
    elif False and (not dfa.isfinite() or m**2 <= dfa.cardinality()):
        sys.stdout.write("Mogulegt!\n")
        seen = set()
        while len(seen) < m:
            try:
                k = random.randint(dfa.minimum_word_length(), dfa.maximum_word_length())
                word = dfa.random_word(k)
                if word not in seen:
                    seen.add(word)
                    sys.stdout.write(f"{word}\n")
            except ValueError:
                pass
    else:
        sys.stdout.write("Mogulegt!\n")
        gen = dfa.successors('', strict=False)
        for i in range(m):
            sys.stdout.write(f"{next(gen)}\n")
