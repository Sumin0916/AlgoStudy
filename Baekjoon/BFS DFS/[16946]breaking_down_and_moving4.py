import sys
from collections import deque

def bfs_search(start, color):
    global visited, res
    queue = deque()
    queue.append(start)
    visited[start[0]][start[1]] = True
    linked_num = 1
    mem_points = [start]

    while queue:
        row, col = queue.popleft()
        for dr, dc in direc:
            nrow = row + dr
            ncol = col + dc
            if 0 <= nrow < N and 0 <= ncol < M:
                if not visited[nrow][ncol] and graph[nrow][ncol] == "0":
                    linked_num += 1
                    visited[nrow][ncol] = True
                    mem_points.append((nrow, ncol))
                    queue.append((nrow, ncol))
    
    for r, c in mem_points:
        res[r][c] = (linked_num, color)

input = sys.stdin.readline

N, M = map(int, input().split())
graph = list(list(input().rstrip()) for _ in range(N))

direc = [[1, 0], [-1, 0], [0, 1], [0, -1]]
res = [[(0, 0) for _ in range(M)] for _ in range(N)]
visited = [[False for _ in range(M)] for _ in range(N)]
p_lst = []
c = 1

for i in range(N):
    for j in range(M):
        if graph[i][j] == "0" and not visited[i][j]:
            bfs_search((i, j), c)
            c += 1

        elif graph[i][j] == "1":
            p_lst.append((i, j))

for r, c in p_lst:
    color_set = set()
    linked_num = 1
    for dr, dc in direc:
        nr = dr + r
        nc = dc + c
        if 0 <= nr < N and 0 <= nc < M:
            if graph[nr][nc] == "0":
                if res[nr][nc][1] not in color_set:
                    linked_num += res[nr][nc][0]
                    color_set.add(res[nr][nc][1])
    linked_num %= 10
    graph[r][c] = str(linked_num)

for i in graph:
    print("".join(i))
