import sys
from collections import deque
r = sys.stdin.readline

m, n = map(int, input().rstrip().split())
box = []
time = -1
point_list = deque()

for i in range(n):
    row = list(map(int, input().split()))
    for j in range(m):
        if row[j] == 1:
            point_list.append([i, j])
    box.append(row)

while point_list:
    now_turn = len(point_list)
    for i in range(now_turn):
        row, col = point_list.popleft()
        direc = [[row + 1, col], [row - 1, col], [row, col + 1], [row, col - 1]]
        for r, c in direc:
            if 0 <= r < n and 0 <= c < m and box[r][c] == 0:
                point_list.append([r, c])
        if i == now_turn - 1:
            time += 1

print(time)

