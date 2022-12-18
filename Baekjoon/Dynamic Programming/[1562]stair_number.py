N = int(input())
dp = [[0 for _ in range(1<<10)] for _ in range(10)]
full = (1<<10)-1

for i in range(1, 10):
    dp[i][1<<i] = 1

for i in range(1, N):
    next_dp = [[0 for _ in range(1<<10)] for _ in range(10)]
    for j in range(10):
        for k in range(full+1):
            if j < 9:
                next_dp[j][k | (1<<j)] += dp[j+1][k] % 1000000000
            if j > 0:
                next_dp[j][k | (1<<j)] += dp[j-1][k] % 1000000000
    dp = next_dp

print(sum(dp[i][full] for i in range(10)) % 1000000000)
