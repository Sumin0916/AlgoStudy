s1 = input()
s2 = input()
l1 = len(s1)
l2 = len(s2)
dp = [list([0, ""] for _ in range(l2+1)) for _ in range(l1+1)]

for i in range(1, l1+1):
    for j in range(1, l2+1):
        if s1[i-1] == s2[j-1]:
            dp[i][j][0] = dp[i-1][j-1][0] + 1
            dp[i][j][1] = dp[i-1][j-1][1] + s2[j-1]
        else:
            if dp[i-1][j][0] > dp[i][j-1][0]:
                dp[i][j][0] = dp[i-1][j][0]
                dp[i][j][1] = dp[i-1][j][1]
            else:
                dp[i][j][0] = dp[i][j-1][0]
                dp[i][j][1] = dp[i][j-1][1]
print(dp[l1][l2][0])
print(dp[l1][l2][1])

