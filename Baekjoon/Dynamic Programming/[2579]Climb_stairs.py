n = int(input())
stair = list((input() for _ in range(n)))
score = [0 for _ in range(n)]

score[0] = stair[0]
score[1] = stair[0] + stair[1]
score[2] = max(stair[0] + stair[2], stair[1] + stair[2])

for i in range(3, n):
    score[i] = max(score[i - 3] + stair[i-1] + stair[i], score[i - 2] + stair[i])

print(score[n-1])

n = int(input())
s = [0 for i in range(301)]
dp = [0 for i in range(301)]
for i in range(n):
    s[i] = int(input())
dp[0] = s[0]
dp[1] = s[0] + s[1]
dp[2] = max(s[1] + s[2], s[0] + s[2])
for i in range(3, n):
    dp[i] = max(dp[i - 3] + s[i - 1] + s[i], dp[i - 2] + s[i])
print(dp[n - 1])