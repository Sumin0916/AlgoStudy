import sys
import heapq

input = sys.stdin.readline
INF = 1000001
N, E = map(int, input().split())
graph = [list() for _ in range(N+1)]


def dijkstra_algo(start):
    heap = []
    heapq.heappush(heap, [0, start])
    distance = [INF] * (N+1)
    distance[start] = 0
    while heap:
        cost, node = heapq.heappop(heap)
        if cost > distance[node]:
            continue
        for v, c in graph[node]:
            if cost + c < distance[v]:
                distance[v] = cost + c
                heapq.heappush(heap, [distance[v], v])
    return distance


for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

v1, v2 = map(int, input().split())

start_dis = dijkstra_algo(1)
end_dis = dijkstra_algo(N)
mid_dis = dijkstra_algo(v1)

res1 = start_dis[v1] + mid_dis[v2] + end_dis[v2]
res2 = start_dis[v2] + mid_dis[v2] + end_dis[v1]
res = min(res1, res2)

if res >= INF:
    print(-1)
else:
    print(res)



