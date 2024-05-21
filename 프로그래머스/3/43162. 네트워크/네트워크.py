visited = list()


def bfs(current, n, computers):
    q = list()
    q.append(current)
    visited[current] = 0
    
    while q:
        node = q[0]
        del q[0]
        
        for idx, connected in enumerate(computers[node]):
            if connected == 1 and visited[idx] == 0:
                q.append(idx)
                visited[idx] = 1
                
    return 1;
            
    

def solution(n, computers):
    answer = 0
    
    global visited
    visited = [0 for i in range(n)]
    
    for i in range(len(computers)):
        if visited[i] == 0:
            answer += bfs(i, n, computers)

    return answer