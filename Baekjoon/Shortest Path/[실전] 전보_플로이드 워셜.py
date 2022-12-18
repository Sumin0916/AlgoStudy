"""
전보
플로이드 워셜 알고리즘
"""
INF = int(1e9)

n, m, start = map(int, input().split())
graph = [[INF] * (n + 1) for _ in range(n+1)]

for i in range(n + 1):
    for j in range(n + 1):
        if i == j:
            graph[i][j] = 0

for _ in range(m):
    a, b, w = map(int, input().split())
    graph[a][b] = w

for a in range(n + 1):
    for b in range(n + 1):
        for c in range(n + 1):
            if a == b or a == c:
                continue
            graph[b][c] = min(graph[b][c], graph[b][a] + graph[a][c])

urban = 0
times = 0

for i in graph[start]:
    if i > 0 and i < INF:
        urban += 1
        times = max(times, i)

print(urban, times)