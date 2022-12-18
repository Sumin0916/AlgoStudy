import sys
import heapq

input = sys.stdin.readline

N, M = map(int, input().split())
degree = [0] * (N+1)
graph = [list() for _ in range(N+1)]
degree[1] = 0

for _ in range(M):
    a, b = map(int, input().split())
    degree[b] += 1
    graph[a].append(b)

heap = []

for i in range(1, N+1):
    if degree[i] == 0:
        heapq.heappush(heap, i)

while heap:
    now = heapq.heappop(heap)
    print(now, end=" ")
    for i in graph[now]:
        degree[i] -= 1
        if degree[i] == 0:
            heapq.heappush(heap, i)
