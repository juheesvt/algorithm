import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().split())

circle = deque([i for i in range(1, n+1)])
seq = []

while circle:
    circle.rotate(-k)
    seq.append(circle.pop())

print('<' + ', '.join(map(str, seq)) + '>')