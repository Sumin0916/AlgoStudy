from bisect import bisect_left
N = int(input())

lines = [list(map(int, input().split())) for _ in range(N)]
lines.sort()
lines = [x[1] for x in lines]
dp = []

for i in lines:
    k = bisect_left(dp, i)
    if len(dp) <= k:
        dp.append(i)
    else:
        dp[k] = i

print(N-len(dp))
