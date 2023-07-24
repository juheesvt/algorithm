import sys
input = sys.stdin.readline


def check_candy_num(n: int) -> int:

    global board
    global answer

    for i in range(n):
        cnt = 1
        for j in range(1, n):
            if board[i][j] == board[i][j - 1]:
                cnt += 1
                answer = max(cnt, answer)
            else:
                cnt = 1

        cnt = 1
        for j in range(1, n):
            if board[j][i] == board[j - 1][i]:
                cnt += 1
                answer = max(answer, cnt)
            else:
                cnt = 1

n = int(input())
board = [ [] for i in range(n)]

for i in range(n):
    board[i] = list(input().rstrip())

answer = 1
for i in range(n):
    for j in range(n):
        if j + 1 < n:
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
            check_candy_num(n)
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]

        if i + 1 < n:
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
            check_candy_num(n)
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]

print(answer)
