import sys
from collections import deque
input = sys.stdin.readline


if __name__ == "__main__":

    n = int(input())
    nums = list(map(int, input().split()))

    answer = list()
    for i in range(n):
        answer.insert(i - nums[i], i + 1)

    for i in answer:
        print(i, end=" ")


