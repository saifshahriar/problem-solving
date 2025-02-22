#!/usr/bin/env python3

# Author: Saif Shahriar

from math import factorial as fact


def sol():
    s = int(input())
    print(f"{fact(s)}")


def main():
    test_cases = int(input())
    for _ in range(test_cases):
        sol()


if __name__ == "__main__":
    main()
