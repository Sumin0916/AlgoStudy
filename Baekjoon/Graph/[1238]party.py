import sys
import heapq
input = sys.stdin.readline
N, M, X = map(int, input().split())
INF = 100001


def djikstra(start, end):
    heap = []
    heapq.heappush(heap, [0, start])
    distance = [INF] * (N + 1)
    distance[start] = 0
    while heap:
        cost, node = heapq.heappop(heap)
        for v, t in graph[node]:
            if cost + t < distance[v]:
                distance[v] = cost + t
                heapq.heappush(heap, [distance[v], v])
    if start == X:
        return distance[end]

    return distance[end] + djikstra(end, start)


graph = [list() for _ in range(N+1)]

for _ in range(M):
    a, b, t = map(int, input().split())
    graph[a].append([b, t])

max_res = 0

for i in range(1, N+1):
    max_res = max(max_res, djikstra(i, X))

print(max_res)
