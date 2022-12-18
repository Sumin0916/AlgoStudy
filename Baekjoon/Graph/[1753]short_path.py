import sys
import heapq

input = sys.stdin.readline
INF = 300000

V, E = map(int, input().split())
start = int(input())
graph = [list() for _ in range(V+1)]
heap = []
path_len = [INF] * (V+1)
path_len[start] = 0
heapq.heappush(heap, [0, start])
for _ in range(E):
    u, v, w = map(int, input().split())
    graph[u].append([w, v])

while heap:
    node = heapq.heappop(heap)[1]
    for w, v in graph[node]:
        if path_len[node] + w < path_len[v]:
            heapq.heappush(heap, [path_len[node] + w, v])
            path_len[v] = path_len[node] + w

for i in range(1, V+1):
    if path_len[i] == INF:
        print("INF")
    else:
        print(path_len[i])
