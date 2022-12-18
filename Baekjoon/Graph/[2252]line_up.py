import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list() for _ in range(N+1)]
num_edge = [0 for _ in range(N+1)]
num_edge[0] = -1

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    num_edge[b] += 1
queue = deque()
for i in range(1, N+1):
    if num_edge[i] == 0:
        queue.append(i)
res = []
while queue:
    node = queue.popleft()
    res.append(node)
    for i in graph[node]:
        num_edge[i] -= 1
        if num_edge[i] == 0:
            queue.append(i)
print(*res)
