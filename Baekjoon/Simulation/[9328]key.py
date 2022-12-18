import sys
import copy
from collections import deque

input = sys.stdin.readline

T = int(input())
direc = [(1, 0), (-1, 0), (0, 1), (0, -1)]

def bfs(h, w, key, graph):
    visited = [[0] * (w) for _ in range(h)]
    documemt = 0
    queue = deque()
    queue.append([0, 0])
    visited[0][0] = 1

    while queue:
        now_row, now_col = queue.popleft()

        for dr, dc in direc:
            nr, nc = dr+now_row, dc+now_col

            if 0 <= nr < h and 0 <= nc < w and not visited[nr][nc]:
                tile_type = graph[nr][nc]
                
                if tile_type == "*":
                    continue

                if tile_type == ".":
                    queue.append([nr, nc])
                    visited[nr][nc] = 1
                
                elif tile_type == "$":
                    documemt += 1
                    queue.append([nr, nc])
                    visited[nr][nc] = 1
                    graph[nr][nc] = "."

                elif tile_type.islower():
                    key.add(tile_type)
                    graph[nr][nc] = "."
                    visited = [[0] * (w) for _ in range(h)]
                    visited[0][0] = 1
                    queue = deque()
                    queue.append([nr, nc])

                elif tile_type.isupper():
                    if tile_type.lower() in key:
                        queue.append([nr, nc])
                        visited[nr][nc] = 1
                        graph[nr][nc] = "."

    return documemt

for _ in range(T):
    h, w = map(int, input().split())
    h += 2
    w += 2
    graph = [["." for _ in range(w)]]

    for i in range(h-2):
        graph.append(["."] + list(input().rstrip()) + ["."])

    graph.append(["." for _ in range(w)])
    key = input().rstrip()

    if key == "0":
        key = set()
    else:
        key = set(list(key))

    print(bfs(h, w, key, graph))
    