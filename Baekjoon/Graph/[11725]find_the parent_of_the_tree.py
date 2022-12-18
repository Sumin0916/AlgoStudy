import sys
from collections import deque

input = sys.stdin.readline

N = int(input())
graph = [list() for _ in range(N+1)]


def find_mom_node(graph, start):  #BFS기법 활용
    global N
    visited = [False] * (N+1)
    mem = [None] * (N+1)
    queue = deque()
    queue.append([start, start])
    while queue:
        mnode, node = queue.popleft()
        visited[node] = True
        mem[node] = mnode
        for n in graph[node]:
            if not visited[n]:
                queue.append([node, n])
    return mem


for _ in range(N-1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

res = find_mom_node(graph, 1)
for i in range(2, N+1):
    print(res[i])

