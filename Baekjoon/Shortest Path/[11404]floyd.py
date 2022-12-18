import sys

input = sys.stdin.readline

INF = 10000000001
n = int(input())
m = int(input())
graph = [list(INF for _ in range(n+1)) for _ in range(n+1)]

for i in range(1, n+1):
    graph[i][i] = 0
for _ in range(m):
    a, b, c = map(int, input().split())
    if graph[a][b] == INF:
        graph[a][b] = c
    else:
        graph[a][b] = min(graph[a][b], c)

for i in range(1, n+1):
    for j in range(1, n+1):
        for k in range(1, n+1):
            graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

for i in range(1, n+1):
    for j in range(1, n+1):
        if graph[i][j] != INF:
            print(graph[i][j], end=" ")
        else:
            print(0, end=" ")
    print()
