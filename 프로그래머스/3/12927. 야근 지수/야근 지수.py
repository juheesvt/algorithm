import heapq

def solution(n, works):
    answer = 0
    
    pq = []
    for w in works:
        heapq.heappush(pq, -w)
        
    while n > 0:
        if not pq:
            break
        num = heapq.heappop(pq)
        if num + 1 < 0:
            heapq.heappush(pq, num + 1)
        n -= 1
        
    while pq:
        answer += heapq.heappop(pq) ** 2

    return answer