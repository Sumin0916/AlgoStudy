import sys

input = sys.stdin.readline

m, n = map(int, input().rstrip().split())  # 가로 세로
box = [list(map(int, list(input().rstrip().split()))) for _ in range(n)]


def judge(array, i, j, n, m):
    direc = [False] * 4  # 동 서 남 북
    res = []
    if i != 0:
        direc[3] = (-1, 0)
    if i != n - 1:
        direc[2] = (1, 0)
    if j != 0:
        direc[1] = (0, -1)
    if j != m - 1:
        direc[0] = (0, 1)

    for r in direc:
        if r:
            if array[r[0]+i][r[1]+j] == 0:
                res.append([r[0]+i, r[1]+j])
    return res


def need(array, m, n, time):
    for i in range(n):
        for j in range(m):
            if array[i][j] == 0:
                return -1
    return time


time = 0

while True:
    point_lst = []
    for i in range(n):
        for j in range(m):
            if box[i][j] == 1:
                point_lst.extend(judge(box, i, j, n, m))
    if point_lst:
        for i, j in point_lst:
            box[i][j] = 1
        time += 1
    else:
        time = need(box, m, n, time)
        if time == -1:
            print(-1)
            break
        else:
            print(time)
            break

