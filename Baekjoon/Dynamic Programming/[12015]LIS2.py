from bisect import bisect_left

N = int(input())
ary = list(map(int, input().split()))
dp = []

for i in ary:
    k = bisect_left(dp, i)
    if len(dp) <= k:
        dp.append(i)
    else:
        dp[k] = i
print(len(dp))
