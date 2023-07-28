import sys

input = sys.stdin.readline

n = int(input())
stair = [0 for i in range(n)]
cache = [0 for i in range(n)]

for i in range(n):
    stair[i] = int(input())

if n <= 2:
    print(sum(stair))
else:
    cache[0] = stair[0]
    cache[1] = stair[0] + stair[1]
    for i in range(2, n):
        cache[i] = max(cache[i - 3] + stair[i - 1] + stair[i], cache[i - 2] + stair[i])
    print(cache[-1])
