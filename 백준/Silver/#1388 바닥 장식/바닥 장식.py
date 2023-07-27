import sys

input = sys.stdin.readline

def dfs(x, y, type):
    global floor, visited, n, m

    visited[x][y] = 1

    if type == "-" and y == m - 1 or type == "|" and x == n - 1:
        return 1
    
    if type == "-":
        nx, ny = x, y + 1
    else:
        nx, ny = x + 1, y
    
    
    if 0 <= nx and nx < n and 0 <= ny and ny < m:
        if type == floor[nx][ny] and not visited[nx][ny]:
            return dfs(nx, ny, floor[nx][ny])
        else:
            return 1

    else:
        return 0

n, m = list(map(int, input().split()))
floor = [[] for i in range(n)]
visited = [[0] * m for i in range(n)]

for i in range(n):
    floor[i] = list(input().rstrip())

cnt = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j]:

            cnt += dfs(i, j, floor[i][j])
        

print(cnt)