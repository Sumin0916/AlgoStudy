import sys

input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
dp = [list([0, 0, 0] for _ in range(N)) for _ in range(N)]
moving_case = {0: [0, 2], 1: [1, 2], 2: [0, 1, 2]}
direc = {0: [0, 1], 1: [1, 0], 2: [1, 1]}
dp[0][1][0] = 1


def dynamic(row, col, stat):
    for d in moving_case[stat]:
        r, c = direc[d]
        nr, nc = row + r, col + c
        if nr < N and nc < N and graph[nr][nc] != 1:
            if d != 2:
                dp[nr][nc][d] += dp[row][col][stat]
            else:
                if not (graph[row][col+1] or graph[row+1][col]):
                    dp[nr][nc][d] += dp[row][col][stat]


for i in range(N):
    for j in range(N):
        for d in range(3):
            if dp[i][j][d] != 0 and graph[i][j] != 1:
                dynamic(i, j, d)

print(sum(dp[N-1][N-1]))
