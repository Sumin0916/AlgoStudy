import sys

input = sys.stdin.readline

N = int(input())
nlst = list(map(int, input().split()))
M = int(input())
dp = list(list(0 for _ in range(N)) for _ in range(N))

for i in range(N):
    dp[i][i] = 1

for i in range(N-1):
    if nlst[i+1] == nlst[i]:
        dp[i][i+1] = 1

for i in range(2, N):
    for j in range(N-i):
        if nlst[j] == nlst[i+j] and dp[j+1][i+j-1]:
            dp[j][i+j] = 1


for _ in range(M):
    S, E = map(int, input().split())
    print(dp[S-1][E-1])