from collections import deque

"""
BFS 두 번째 연습
"""

def bfs_search(start, graph):
    visited = [False] * len(graph)
    visited[start] = True
    queue = deque([start])

    while queue:
        node = queue.popleft()
        print(node, end=" ")

        for n in graph[node]:
            if not visited[n]:
                queue.append(n)
                visited[n] = True


graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

bfs_search(1, graph)