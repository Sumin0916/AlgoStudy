"""
미래도시
다익스트라 알고리즘 이용
"""

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, m, s = map(int, input().split())
graph = [[] for _ in range(n +1)]
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

def dijkstra(start):
    heap = []
    distance[start] = 0
    heapq.heappush(heap, (distance[start], start))
    while heap:
        dis, node = heapq.heappop(heap)
        if distance[node] < dis:
            continue
        for i in graph[node]:
            weight = dis + i[1]
            if distance[i[0]] > weight:
                distance[i[0]] = weight
                heapq.heappush(heap, (weight, i[0]))

urban = 0
times = 0
dijkstra(s)

for i in distance[1:]:
    if i > 0:
        urban += 1
        times = max(times, i)

print(urban, times)
