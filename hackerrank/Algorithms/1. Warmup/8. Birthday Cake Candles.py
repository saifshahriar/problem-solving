#!/bin/python3

_ = input()
candles = list(map(int, input().split(' ')))
print(candles.count(max(candles)))