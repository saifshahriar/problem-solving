from math import ceil

for _ in range(int(input())):
    n, m = map(int, input().split())
    print(ceil((n - 2) / 3) * ceil((m - 2) / 3))
