import sys

input = sys.stdin.readline

n, m, r = map(int, input().split())
INF = 15000
max_res = 0

graph = [list(INF for _ in range(n+1)) for _ in range(n+1)]
item = [0]
item.extend(list(map(int, input().split())))

for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a][b] = l
    graph[b][a] = l

for i in range(1, n+1):
    graph[i][i] = 0

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

for i in range(1, n+1):
    res = 0
    for j in range(1, n+1):
        if graph[i][j] <= m:
            res += item[j]
    max_res = max(max_res, res)

print(max_res)
