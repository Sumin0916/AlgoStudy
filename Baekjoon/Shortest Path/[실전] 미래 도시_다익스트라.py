"""
미래 도시
다익스트라 알고리즘 이용
"""
import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
graph = [[] for i in range(n+1)]
distance = [INF] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
x, k = map(int, input().split())

def dijkstra(start, end):
    global distance

    h = []
    distance[start] = 0
    heapq.heappush(h, (distance[start], start))
    while h:
        weight, now_node = heapq.heappop(h)
        if distance[now_node] < weight:
            continue

        for i in graph[now_node]:
            new_weight = 1 + weight
            if distance[i] > new_weight:
                distance[i] = new_weight
                heapq.heappush(h, (new_weight, i))
    res = distance[end]
    distance = [INF] * (n + 1)
    return res

res1 = dijkstra(1, k)
res2 = dijkstra(k, x)
if res1 + res2 >= INF:
    print(-1)
else:
    print(res1 + res2)