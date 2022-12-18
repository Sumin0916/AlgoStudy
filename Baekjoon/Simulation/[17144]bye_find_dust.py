import sys

input = sys.stdin.readline
R, C, T = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(R)]
direc = [[1, 0], [-1, 0], [0, 1], [0, -1]]


def one_time_spread():
    add_lst = []
    sub_lst = []
    for i in range(R):
        for j in range(C):
            count = 0
            if room[i][j] > 0:
                for r, c in direc:
                    nr = i + r
                    nc = j + c
                    if 0 <= nr < R and 0 <= nc < C:
                        if room[nr][nc] != -1:
                            count += 1
                            add_lst.append([nr, nc, room[i][j]//5])
                sub_lst.append([i, j, (room[i][j]//5) * count])
    for r, c, a in add_lst:
        room[r][c] += a
    for r, c, s in sub_lst:
        room[r][c] -= s
    return


def clockwise_direc(row, col):
    if room[row][col] == -1:
        return
    if col == 0 and row > 0:
        room[row][col] = room[row-1][col]
        clockwise_direc(row-1, col)
    elif row == 0 and col < C-1:
        room[row][col] = room[row][col+1]
        clockwise_direc(row, col+1)
    elif col == C-1 and row < air_row[0]:
        room[row][col] = room[row+1][col]
        clockwise_direc(row+1, col)
    elif row == air_row[0] and col > 0:
        room[row][col] = room[row][col-1]
        clockwise_direc(row, col-1)


def reverse_clockwise(row, col):
    if room[row][col] == -1:
        return
    if col == 0 and row < R-1:
        room[row][col] = room[row+1][col]
        reverse_clockwise(row+1, col)
    elif row == R-1 and col < C-1:
        room[row][col] = room[row][col+1]
        reverse_clockwise(row, col+1)
    elif col == C-1 and row > air_row[1]:
        room[row][col] = room[row-1][col]
        reverse_clockwise(row-1, col)
    elif row == air_row[1] and col > 0:
        room[row][col] = room[row][col-1]
        reverse_clockwise(row, col-1)


air_row = []
for i in range(R):
    if room[i][0] == -1:
        air_row.append(i)


for _ in range(T):
    one_time_spread()
    clockwise_direc(air_row[0]-1, 0)
    room[air_row[0]][1] = 0
    reverse_clockwise(air_row[1]+1, 0)
    room[air_row[1]][1] = 0

room[air_row[0]][0] = 0
room[air_row[1]][0] = 0
print(sum(list(map(sum, room))))

