D = int(input())

dp = [1, 0, 0, 0, 0, 0, 0, 0]

for i in range(D):
    temp = [0] * 8
    temp[0] = dp[1] + dp[2]
    temp[1] = dp[0] + dp[2] + dp[4]
    temp[2] = dp[0] + dp[1] + dp[4] + dp[3]
    temp[3] = dp[2] + dp[4] + dp[5] + dp[7]
    temp[4] = dp[1] + dp[2] + dp[3] + dp[5]
    temp[5] = dp[4] + dp[3] + dp[6]
    temp[6] = dp[5] + dp[7]
    temp[7] = dp[6] + dp[3]
    dp = temp

print(dp[0]%1000000007)
