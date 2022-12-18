"""
DFS 스택 사용  풀이
"""

def dfs(start, graph):
    visited = [False] * len(graph)
    stack = [start]
    visited[start] = True
    node = start

    print(node, end=" ")
    while stack:
        node = stack[-1]
        
        if visited[graph[node][-1]]:
            stack.pop()
            
        for n in graph[node]:
            if not visited[n]:
                stack.append(n)
                visited[n] = True
                print(n, end=" ")
                break
        

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

dfs(1, graph)