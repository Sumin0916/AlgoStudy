n = int(input())
roads = list(map(int, input().split()))
cities = list(map(int, input().split()))
m = cities[0]
res = 0

for i in range(n-1):
    c = cities[i]
    if m > c:
        m = c
    res += m * roads[i]

print(res)
