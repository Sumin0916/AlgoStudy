N, M = map(int, input().split())
mem = [0] + list(map(int, input().split()))
cost = [0] + list(map(int, input().split()))
res = sum(cost)
ans = sum(cost)
dp = list(list(0 for _ in range(res+1)) for _ in range(N+1))

for i in range(1, N+1):
    m = mem[i]
    c = cost[i]
    for j in range(1, res+1):
        if j < c:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(m + dp[i-1][j-c], dp[i-1][j])
        if dp[i][j] >= M:
            ans = min(ans, j)

if M != 0:
    print(ans)
else:
    print(0)
