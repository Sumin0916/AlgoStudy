import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
dp = [0] * n

for i in range(n):
    pre_num_stat = 0
    for j in range(i):
        if a[j] < a[i]:
            if pre_num_stat < dp[j]:
                pre_num_stat = dp[j]
    dp[i] = pre_num_stat + 1
print(max(dp))
    
