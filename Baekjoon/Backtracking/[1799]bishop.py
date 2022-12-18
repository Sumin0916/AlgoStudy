import sys

N = int(input())
board = list(list(map(int, input().split())) for _ in range(N))
ans = 0
BISHOP = -1

def set_board(row, col, num):
    global temp
    for i in range(N):
        nx, ny = row - i, col - i
        if 0 <= nx < N and 0 <= ny < N:
            temp[nx][ny] += num
        nx, ny = row + i, col - i
        if 0 <= nx < N and 0 <= ny < N:
            temp[nx][ny] += num
        nx, ny = row - i, col + i
        if 0 <= nx < N and 0 <= ny < N:
            temp[nx][ny] += num
        nx, ny = row + i, col + i
        if 0 <= nx < N and 0 <= ny < N:
            temp[nx][ny] += num


def simulator(order, cnt):
    global board, ans, bishop_lst, temp
    if order >= lst_len:
        ans = max(ans, cnt)
        return
    row, col = can_place_lst[order]
    if temp[row][col] == 0:
            set_board(row, col, 1)
            simulator(order+1, cnt+1)
            set_board(row, col, -1)
            simulator(order+1, cnt)
    else:
        simulator(order+1, cnt)

can_place_lst = []
temp = [[0]*N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            if (i+j) % 2 == 0:
                can_place_lst.append([i, j])

lst_len = len(can_place_lst)
simulator(0, 0)
r1 = ans

ans = 0
can_place_lst = []
temp = [[0]*N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            if (i+j) % 2 == 1:
                can_place_lst.append([i, j])

lst_len = len(can_place_lst)
simulator(0, 0)
r2 = ans

print(r1+r2)
