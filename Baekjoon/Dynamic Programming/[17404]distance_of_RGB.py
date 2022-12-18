import sys
import copy

input = sys.stdin.readline
INF = 1e11
N = int(input())
house_lst = list(list(map(int, input().split())) for _ in range(N))
combi = [[house_lst[0][0], INF, INF], [INF, house_lst[0][1], INF], [INF, INF, house_lst[0][2]]]
res = INF

for c in range(3):
    dp = copy.deepcopy(house_lst)
    dp[0] = combi[c]
    for i in range(1, N):
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + dp[i][0]
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + dp[i][1]
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + dp[i][2]
    for j in range(3):
        if c != j:
            res = min(res, dp[N-1][j])

print(res)


