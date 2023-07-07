import heapq, sys

input = sys.stdin.readline

max_heap = list()
n = int(input())

for i in range(n):
    command = int(input())
    if command == 0:
        if max_heap:
            num = heapq.heappop(max_heap)
            print(-num)
        else:
            print(0)
    else:
        heapq.heappush(max_heap, -command)
    

