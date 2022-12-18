from collections import deque
NINF = 1000000001
n, m = map(int, input().split())
barrack = [list(map(int, input().split())) for _ in range(n)]
direc = [(1, 0, 0), (0, 1, 0), (0, -1, 0), (-1, 0, 0)]
jump_direc = [(2, 0, 1), (0, 2, 1), (0, -2, 1), (-2, 0, 1)]


def movable_point(graph, level_graph, row, col, stat):
    now_level = graph[row][col]
    level_graph[row][col] = [now_level, stat]
    res = []
    if stat:
        temp = [(row+r, col+c, 1) for r, c, s in direc if 0 <= row+r <= n-1 and 0 <= col+c <= m-1]
    else:
        temp = [(row+r, col+c, 0) for r, c, s in direc if 0 <= row+r <= n-1 and 0 <= col+c <= m-1]
        temp = [(row+r, col+c, 1) for r, c, s in jump_direc if 0 <= row+r <= n-1 and 0 <= col+c <= m-1]

    for r, c, s in temp:
        future_level = graph[r][c]
        route_level = now_level if (now_level > future_level) else future_level
        if s == 1:
            if level_graph[r][c][1] == 1 and level_graph[r][c][0] > route_level:
                level_graph[r][c] = [route_level, 1]
                res.append((r, c, 1))
                level_graph[row][col] = [route_level, stat]

        else:
            if level_graph[r][c][0] > route_level:
                level_graph[r][c] = [route_level, 0]
                level_graph[row][col] = [route_level, stat]
                res.append((r, c, 0))
    return res


def bfs_search(graph):
    if n == 1 and m == 1:
        return graph[n-1][m-1]
    level_map = [[[NINF, 0] for _ in range(m)] for _ in range(n)]
    queue = deque()
    queue.append((0, 0, 0))
    while queue:
        row, col, stat = queue.popleft()
        if 0 <= row < n and 0 <= col < m:
            lst = movable_point(graph, level_map, row, col, stat)
            if lst:
                queue.extend(lst)
    for r in level_map:
        print(r)
    return level_map[n-1][m-1]


print(bfs_search(barrack))
