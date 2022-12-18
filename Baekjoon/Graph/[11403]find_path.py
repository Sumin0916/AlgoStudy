import sys

input = sys.stdin.readline
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
res = [[0 for _ in range(n)] for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if graph[i][k] + graph[k][j] == 2:
                graph[i][j] = 1

for c in graph:
    print(" ".join(list(map(str, c))))
