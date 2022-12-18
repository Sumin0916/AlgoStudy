"""
게임 개발
"""

n, m = map(int, input().split())
c_row, c_col, d = map(int, input().split())
map_arr = list()
moving_count = 1
direc_left = [
    ((-1, 0), (1, 0)), # 앞쪽, 뒤쪽
    ((0, 1), (0, -1)),
    ((1, 0), (-1, 0)),
    ((0, -1), (0, 1))
]
for _ in range(n):
    map_arr.append(list(map(int, input().split())))
nd =  d
turn_time = 0

while True:
    map_arr[c_row][c_col] = 8
    for i in range(n):
        print(map_arr[i])
    print()

    turn_time += 1
    nd -= 1
    if nd == -1:
        nd = 3
    temp_row = c_row + direc_left[nd][0][0] # 임시 직진
    temp_col = c_col + direc_left[nd][0][1]

    if 0 <= temp_row <= n-1 and 0 <= temp_col <= m-1 and map_arr[temp_row][temp_col] == 0:
        c_row = temp_row
        c_col = temp_col
        moving_count += 1
        turn_time = 0

    if turn_time == 4:
        temp_row = c_row + direc_left[nd][1][0] # 임시 후진
        temp_col = c_col + direc_left[nd][1][1]

        if 0 <= temp_row <= n-1 and 0 <= temp_col <= m-1 and map_arr[temp_row][temp_col] == 0:
            c_col = temp_col
            c_row = temp_row
            moving_count += 1
            turn_time = 0

        else:
            break
print(moving_count)