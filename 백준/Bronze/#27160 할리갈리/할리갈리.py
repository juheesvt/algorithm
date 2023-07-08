import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n = int(input())
    fruit_dict = {"STRAWBERRY": 0, "BANANA": 0, "LIME": 0, "PLUM": 0}

    for i in range(n):
        fruit, num = input().split()
        fruit_dict[fruit] += int(num)
    
    print("YES" if 5 in fruit_dict.values() else "NO")