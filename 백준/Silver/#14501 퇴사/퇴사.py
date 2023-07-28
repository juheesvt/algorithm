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