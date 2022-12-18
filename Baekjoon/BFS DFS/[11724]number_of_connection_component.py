from collections import deque
import sys

input = sys.stdin.readline
N, M = map(int, input().rstrip().split())
graph = [[] for _ in range(N+1)]
visited = [False] * (N + 1)


def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


for _ in range(M):
    start, end = map(int, input().rstrip().split())
    graph[start].append(end)
    graph[end].append(start)


color = 0
for i in range(1, N+1):
    if not visited[i]:
        bfs(graph, i, visited)
        color += 1
print(color)
