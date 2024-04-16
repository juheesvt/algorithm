import sys

input = sys.stdin.readline

n, k = map(int, input().split())

josephus = [i for i in range(1, n + 1)]
answers = []

count, idx = 0, 0
while josephus:
    count += 1
    if count == k:
        answers.append(josephus[idx])
        if idx == len(josephus) - 1:
            del josephus[idx]
            idx = 0
        else:
            del josephus[idx]
        count = 0
    else:
        idx += 1
    
    if idx == len(josephus):
        idx = 0

answer = "<"
for i in answers:
    answer += str(i) + ", "
else:
    answer = answer[:-2]
    answer += ">"
print(answer)
