#!/usr/bin/env python3

# Author: Saif Shahriar

from math import factorial as fact


def sol():
    s = (input()).split()
    n = len(s)
    cnt = [s.count(e) for e in set(s)]
    f = 1

    for e in cnt:
        f *= fact(e)
    f = int(fact(n) / f)
    print(f"1/{f}")


def main():
    test_cases = int(input())
    for _ in range(test_cases):
        sol()


if __name__ == "__main__":
    main()
