import sys
import copy

sys.setrecursionlimit(10**6)
n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
res = -1

def bfs_search(new_graph, row, col, level):
    global n
    if 0 <= row < n and 0 <= col < n:
        if new_graph[row][col] > level:
            new_graph[row][col] = 0
            bfs_search(new_graph, row+1, col, level)
            bfs_search(new_graph, row-1, col, level)
            bfs_search(new_graph, row, col+1, level)
            bfs_search(new_graph, row, col-1, level)
        else:
            return
    else:
        return

for level in range(101):
    ans = 0
    new_graph = copy.deepcopy(graph)
    for i in range(n):
        for j in range(n):
            if new_graph[i][j] > level:
                ans += 1
                bfs_search(new_graph, i, j, level)
    res = max(res, ans)

print(res)
