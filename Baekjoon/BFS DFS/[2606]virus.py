import sys


def DFS(graph, start):
    global stack, visited
    node = start
    if not visited[node]:
        visited[node] = True
        stack.extend(graph[node])
    else:
        stack.pop()
    if len(stack) < 1:
        return
    DFS(graph, stack[-1])


com_num = int(sys.stdin.readline().rstrip())
edge_num = int(sys.stdin.readline().rstrip())
com_graph = [list() for _ in range(com_num + 1)]
visited = [False] * (com_num + 1)
stack = []

for _ in range(edge_num):
    a, b = map(int, sys.stdin.readline().strip().split())
    com_graph[a].append(b)
    com_graph[b].append(a)

DFS(com_graph, 1)
print(visited.count(True) - 1)
