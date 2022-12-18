from collections import deque

"""
DFS와 BFS
"""

def dfs_search1(graph, node, visited):
    visited[node] = True
    print(node, end=" ")

    for i in sorted(graph[node]):
        if not visited[i]:
            dfs_search1(graph, i, visited)

def dfs_search(graph, start):
    visited = [False] * len(graph)
    stack = [start]

    while stack:
        v = stack.pop()
        visited[v] = True
        print(v, end=" ")

        for i in sorted(graph[v]):
            if not visited[i]:
                stack.append(i)
                visited[i] = True
                break

    print("\n", end="")

def bfs_search(graph, start):
    visited = [False] * len(graph)
    queue = deque([start])
    visited[start] = True

    while queue:
        v = queue.popleft()
        print(v, end=" ")

        for i in sorted(graph[v]):
            if not visited[i]:
                queue.append(i)
                visited[i] = True

nodes, edges, start_num = map(int, input().split())
graph = [[] for _ in  range(nodes + 1)]

for _ in range(edges):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)


visited = [False] * len(graph)

dfs_search(graph, start_num)

bfs_search(graph, start_num)
#for i in range(edges):

