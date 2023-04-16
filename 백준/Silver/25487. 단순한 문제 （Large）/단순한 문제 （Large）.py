import sys

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        print(min(list(map(int, sys.stdin.readline().split()))))
