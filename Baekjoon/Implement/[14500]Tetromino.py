import sys
import copy
input = sys.stdin.readline

n, m = map(int, input().split())
tetrominos = [
    [
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [1, 1, 1, 1]
    ],
    [
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 0, 1, 1],
        [0, 0, 1, 1]
    ],
    [
        [0, 0, 0, 0],
        [0, 0, 0, 0],
        [0, 1, 1, 1],
        [0, 0, 1, 0]
    ],
    [
        [0, 0, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 1, 0],
        [0, 0, 1, 1]
    ],
    [
        [0, 0, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 1, 1],
        [0, 0, 0, 1]
    ]
]


def rotate(block):
    ret = copy.deepcopy(block)
    for r in range(4):
        for c in range(4):
            block[c][3-r] = ret[r][c]
    return block


def flip(block):
    for i in range(2):
        for j in range(4):
            block[j][i], block[j][3 - i] = block[j][3 - i], block[j][i]
    return block


def get_points(block):
    points = []
    for i in range(4):
        for j in range(4):
            if block[i][j] == 1:
                points.append([i, j])
    return points


def get_score(points, ary, row, col):
    score = 0
    std_r = points[0][0]
    std_c = points[0][1]
    for i in range(4):
        points[i][0] -= std_r
        points[i][1] -= std_c
    for i in range(4):
        new_row = row + points[i][0]
        new_col = col + points[i][1]
        if 0 <= new_row < n and 0 <= new_col < m:
            score += ary[new_row][new_col]
        else:
            return -1
    return score


array = [list(map(int, input().split())) for _ in range(n)]
res = 0
point_block = []
point_block.append(get_points(tetrominos[0]))
point_block.append(get_points(tetrominos[1]))

for i in range(5):
    for r in range(4):
        if i != 1:
            rotate(tetrominos[i])
        for f in range(2):
            if not (i == 0 or i == 1):
                flip(tetrominos[i])
                point_block.append(get_points(tetrominos[i]))
for i in range(n):
    for j in range(m):
        for p in point_block:
            score = get_score(p, array, i, j)
            if res < score:
                res = score

print(res)
