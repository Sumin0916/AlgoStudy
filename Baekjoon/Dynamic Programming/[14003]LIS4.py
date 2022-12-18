from bisect import bisect_left

N = int(input())
ary = [0] + list(map(int, input().split()))
dp = [0] * (N+1)
refrence = [-1*(1e10)]

for i in range(1, N+1):
    if refrence[-1] < ary[i]:
        refrence.append(ary[i])
        dp[i] = len(refrence) - 1
        ans = dp[i]
    else:
        dp[i] = bisect_left(refrence, ary[i])
        refrence[dp[i]] = ary[i]

res = []
print(ans)

for i in range(N, 0, -1):
    if dp[i] == ans:
        res.append(ary[i])
        ans -= 1

res.reverse()
print(*res)
