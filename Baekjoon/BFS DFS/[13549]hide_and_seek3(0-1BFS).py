from collections import deque

n, k = map(int, input().split())
INF = 200000
dist = [INF] * (200000)
dist[n] = 0
d = deque()
d.appendleft(n)

while d:
    vertex = d.popleft()
    if vertex == k:
        print(dist[k])
        break
    for v in [vertex-1, vertex+1, 2*vertex]:
        if not (0 <= v < 200000):
            continue
        if dist[vertex] < dist[v]:
            if v != 2 * vertex:
                dist[v] = dist[vertex] + 1
                d.append(v)
            else:
                dist[v] = dist[vertex]
                d.appendleft(v)
