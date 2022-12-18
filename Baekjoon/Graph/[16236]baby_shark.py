import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
graph = [list(map(int, input().split())) for _ in range(n)]
size = [2, 2]
t = 0
for i in range(n):
    for j in range(n):
        if graph[i][j] == 9:
            shark_point = (i, j)


def can_swimming(graph, row, col, visited):
    global size
    direc = [(-1, 0), (0, -1), (0, 1), (1, 0)]
    lst = []
    for r, c in direc:
        nr = row+r
        nc = col+c
        if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc]:
            if graph[nr][nc] <= size[0]:
                lst.append((nr, nc))
                visited[nr][nc] = True
    return lst


def bfs_search(graph, row, col, visited):
    global size
    queue = deque()
    queue.append((row, col))
    elapsed_time = 0
    while True:
        tqueue = deque()
        pray_lst = []
        while queue:
            r, c = queue.popleft()
            if 0 < graph[r][c] < size[0]:
                pray_lst.append((r, c))
            lst = can_swimming(graph, r, c, visited)
            if lst:
                tqueue.extend(lst)
        if pray_lst:
            pray_lst.sort()
            r, c = pray_lst[0][0], pray_lst[0][1]
            if size[0] < 8:
                if size[1] > 1:
                    size[1] -= 1
                else:
                    size[1] = size[0]+1
                    size[0] += 1
            graph[row][col] = 0
            graph[r][c] = 9
            return (r, c, elapsed_time)
        elapsed_time += 1
        if tqueue:
            queue = tqueue
        else:
            return False


while True:
    visited = [[False for _ in range(n)] for _ in range(n)]
    visited[shark_point[0]][shark_point[1]] = True
    shark_point = bfs_search(graph, shark_point[0], shark_point[1], visited)
    if shark_point:
        t += shark_point[2]
    else:
        print(t)
        break

