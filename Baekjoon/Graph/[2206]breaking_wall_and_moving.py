import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())
graph = [list(map(int, list(input().rstrip()))) for _ in range(N)]
visited = [list(False for _ in range(M)) for _ in range(N)]

queue = deque()
direc = [[1, 0], [0, 1], [-1, 0], [0, -1]]
jumping_direc = [[2, 0], [0, 2], [-2, 0], [0, -2]]
queue.append([0, 0, 0])
visited[0][0] = True
distance = 1
res = 0

while queue:
    tqueue = deque()
    while queue:
        row, col, stat = queue.popleft()
        if row == N-1 and col == M-1:
            if stat:
                print(distance+1)
            else:
                print(distance)
            res = 1
            break
        if stat == 1:
            for i in range(4):
                r, c = direc[i]
                nr = row + r
                nc = col + c
                if 0 <= nr < N and 0 <= nc < M:
                    if not visited[nr][nc] and graph[nr][nc] == 0:
                        tqueue.append([nr, nc, 1])
                        visited[nr][nc] = 2

        else:
            for r, c in direc:
                nr = row + r
                nc = col + c
                if 0 <= nr < N and 0 <= nc < M:
                    if visited[nr][nc] != 1:
                        if graph[nr][nc] == 0:
                            tqueue.append([nr, nc, 0])
                            visited[nr][nc] = 1
            for i in range(4):
                r, c = jumping_direc[i]
                a, b = direc[i]
                nr = row + r
                nc = col + c
                if 0 <= nr < N and 0 <= nc < M:
                    if not visited[nr][nc] and graph[nr][nc] == 0 and graph[row+a][col+b] == 1:
                        tqueue.append([nr, nc, 1])
                        visited[nr][nc] = 2

    if res:
        break
    if len(tqueue) == 0:
        print(-1)
        break
    queue = tqueue
    distance += 1
