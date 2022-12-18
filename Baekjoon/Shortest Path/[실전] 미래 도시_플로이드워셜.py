"""
미래 도시
플로이드 워셜 알고리즘
"""

import sys

input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
graph = [[INF] * (n + 1) for i in range(n+1)]

for a in range(n + 1):
    for b in range(n + 1):
        if a == b:
            graph[a][b] = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

x, k = map(int, input().split())

for a in range(n + 1):
    for b in range(n + 1):
        for c in range(n + 1):
            graph[b][c] = min(graph[b][c], graph[b][a] + graph[a][c])

res = graph[1][k] + graph[k][x]

if res >= INF:
    print(-1)
else:
    print(res)