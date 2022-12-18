import collections


point_lst = collections.deque()

n, m = map(int, input().split())
maze = [list(map(int, list(input()))) for _ in range(n)]
visited = [[False for _ in range(m)] for _ in range(n)]

point_lst.append([0, 0])
count = 1
direc = [(1, 0), (0, 1), (0, -1), (-1, 0)]
while True:
    temp_lst = collections.deque()
    while point_lst:
        r, c = point_lst.popleft()
        if (r, c) == (n-1, m-1):
            print(count)
            break
        for a, b in direc:
            tr = r+a
            tc = c+b
            if 0 <= tr < n and 0 <= tc < m:
                if maze[tr][tc] == 1 and not visited[tr][tc]:
                    visited[tr][tc] = True
                    temp_lst.append([tr, tc])
    if (r, c) == (n-1, m-1):
        break
    point_lst = temp_lst
    count += 1
