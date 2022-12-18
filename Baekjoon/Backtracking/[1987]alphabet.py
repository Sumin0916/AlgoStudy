import sys

input = sys.stdin.readline
dc = [-1, 0, 1, 0]
dr = [0, 1, 0, -1]
res = 0
R, C = map(int, input().split())
graph = [list(map(lambda x: ord(x)-65, input().rstrip())) for _ in range(R)]
visited = [False] * (26)
visited[graph[0][0]] = True


def bfs_search(row, col, cnt):
    global res
    res = max(res, cnt)
    for i in range(4):
        nr = row + dr[i]
        nc = col + dc[i]
        if 0 <= nr < R and 0 <= nc < C and not visited[graph[nr][nc]]:
            visited[graph[nr][nc]] = True
            bfs_search(nr, nc, cnt+1)
            visited[graph[nr][nc]] = False


bfs_search(0, 0, 1)
print(res)
