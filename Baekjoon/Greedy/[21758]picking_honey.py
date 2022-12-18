n = int(input())
honey = list(map(int, input().split()))
s = []
s.append(honey[0])
res = 0
for i in range(1, n):
    s.append(s[i-1]+honey[i])

for i in range(1, n-1):
    res = max(res, s[i] - honey[0] + s[n-2] - s[i-1])  # 벌 집 벌

for i in range(1, n-1):
    res = max(res, 2 * s[n-1] - s[i] - honey[0] - honey[i])  # 벌 벌 집

for i in range(1, n-1):
    res = max(res, s[n-2] + s[i-1] - honey[i])  # 집 벌 벌

print(res)
