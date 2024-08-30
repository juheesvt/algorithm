import sys
from collections import deque

input = sys.stdin.readline


dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]


def bfs(i, j):
    global board, answer, n, m
    visited = [[0 for i in range(m)] for i in range(n)]
    q = deque()
    q.append((i, j))

    while q:
        current_x, current_y= q.popleft()

        for k in range(8):
            next_x, next_y = current_x + dx[k], current_y + dy[k]

            if next_x < 0 or next_x >= n or next_y < 0 or next_y >= m:
                continue

            if board[next_x][next_y] == 1:
                return visited[current_x][current_y] + 1
            
            if board[next_x][next_y] == 0 and visited[next_x][next_y] == 0:
                q.append((next_x, next_y))
                visited[next_x][next_y] = visited[current_x][current_y] + 1



n, m = list(map(int, input().split()))
board = [ [] for i in range(n)]
for i in range(n):
    board[i] = list(map(int, input().split()))

answer = list()
for i in range(n):
    for j in range(m):
        if board[i][j] == 0:
            answer.append(bfs(i, j))

print(max(answer))
