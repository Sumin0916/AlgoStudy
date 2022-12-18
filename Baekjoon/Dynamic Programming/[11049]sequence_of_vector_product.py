import sys

input = sys.stdin.readline

N = int(input())
vector = list(list(map(int, input().split())) for _ in range(N))
dp = [[0] * N for _ in range(N)]

for i in range(1, N):
    for j in range(N-i):
        dp[j][j+i] = 2**32
        for k in range(j, j+i):
            dp[j][j+i] = min(dp[j][j+i], dp[j][k] + dp[k+1][j+i] + vector[j][0] * vector[k][1] * vector[j+i][1])

print(dp[0][N-1])