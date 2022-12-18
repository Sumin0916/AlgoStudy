"""
DFS 재귀함수 표현
"""

def recursive_dfs(node, graph, visited):
    visited[node] = True
    print(node, end=" ")

    for n in graph[node]:
        if not visited[n]:
            recursive_dfs(n, graph, visited)

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

visited = [False] * len(graph)

recursive_dfs(1, graph, visited)