import sys

input = sys.stdin.readline

T = 0
P = 1

schedule = list()
n = int(input())

for i in range(n):
    schedule.append(tuple(map(int, input().split())))

# 마지막 상담이 끝난 날짜에 얼마를 얻었는지  
cache = [0 for i in range(n + 1)]
for today in range(len(schedule)):
    for done in range(today + schedule[today][T], n + 1):
        if cache[done] <  cache[today] + schedule[today][P]:
            cache[done] = cache[today] + schedule[today][P]


print(cache[-1])

"""
이전 코드

import sys

input = sys.stdin.readline

T = 0
P = 1

schedule = list()
n = int(input())

for i in range(n):
    schedule.append(tuple(map(int, input().split())))

# 얼마나 걸리는지, 얼마를 얻었는지  -> 얼마나 걸리는지는 저장 안해도댐
cache = [[0, 0] for i in range(n)]
for today, consult in enumerate(schedule):
    if today + consult[T] < n:
        if cache[today + consult[T] - 1][P] < consult[P]:
            cache[today + consult[T] - 1][T] = consult[T] 
            cache[today + consult[T] - 1][P] += consult[P] + cache[today - consult[T] - 1][P]

print(cache)

"""