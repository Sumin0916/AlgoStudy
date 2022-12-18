n, m = map(int, input().split())
if m > n//2:
    m = n-m
i = n
res1 = 1
for _ in range(m):
    res1 *= i
    i -= 1

res2 = 1
for i in range(m, 1, -1):
    res2 *= i

print(res1//res2)
