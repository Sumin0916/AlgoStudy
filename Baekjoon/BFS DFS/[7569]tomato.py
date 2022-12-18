from collections import deque
import sys

input = sys.stdin.readline


col, row, height = map(int, input().split())
box = [[list(map(int, input().split())) for _ in range(row)] for _ in range(height)]


def can_corruption(graph, height, row, col, mh, mr, mc):
    direc = [(0, 1, 0), (0, -1, 0), (0, 0, 1),
             (0, 0, -1), (1, 0, 0), (-1, 0, 0)]
    temp = []
    for h, r, c in direc:
        nh = height+h
        nr = row+r
        nc = col+c
        if 0 <= nh < mh and 0 <= nr < mr and 0 <= nc < mc:
            if graph[nh][nr][nc] == 0:
                temp.append((nh, nr, nc))
    for h, r, c in temp:
        graph[h][r][c] = 1
    if temp:
        return temp
    else:
        return False


def bfs_search(graph):
    queue = deque()
    day = -1
    stat = False
    for i in range(height):
        for j in range(row):
            for k in range(col):
                if graph[i][j][k] == 1:
                    queue.append((i, j, k))
                if graph[i][j][k] == 0:
                    stat = True
    if not queue:
        return -1
    if not stat and queue:
        return 0
    while True:
        day += 1
        temp = []
        while queue:
            h, r, c = queue.popleft()
            res = can_corruption(graph, h, r, c, height, row, col)

            if res:
                temp.extend(res)
        queue.extend(temp)
        if not queue:
            for i in range(height):
                for j in range(row):
                    for k in range(col):
                        if graph[i][j][k] == 0:
                            return -1
            return day


print(bfs_search(box))
