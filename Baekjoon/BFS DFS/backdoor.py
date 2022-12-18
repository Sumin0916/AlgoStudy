import sys
import heapq

INF = int(1e10)
n, m = map(int, sys.stdin.readline().rstrip().split())
visible = list(map(int, sys.stdin.readline().rstrip().split()))
visible[-1] = 0
graph = [[] for _ in range(n)]
distance = [INF]*(n)

for _ in range(m):
    a, b, t = map(int, sys.stdin.readline().rstrip().split())
    graph[a].append((b, t))
    graph[b].append((a, t))

def dijkstra():
    queue = []
    heapq.heappush(queue, (0, 0))
    distance[0] = 0

    while queue:
        dist, now = heapq.heappop(queue)

        if (distance[now] < dist):
            continue
        
        for arrive, cost in graph[now]:
            weight = dist + cost
            if weight < distance[arrive] and not visible[arrive]:
                heapq.heappush(queue, (weight, arrive))
                distance[arrive] = weight

dijkstra()

print(distance[n-1] if distance[n-1]<INF else -1)