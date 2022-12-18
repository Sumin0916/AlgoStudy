"""
체스판 다시 칠하기
"""
board_v1 = [["B", "W"] * 4,["W", "B"] * 4] * 4
board_v2 = [["W", "B"] * 4,["B", "W"] * 4] * 4

def check_diff_min(board_lst):
    res1, res2 = 0, 0

    for i in range(8):
        for j in range(8):
            if board_lst[i][j] != board_v1[i][j]:
                res1 += 1
            
            if board_lst[i][j] != board_v2[i][j]:
                res2 += 1
    
    return min(res1, res2)


n, m = map(int, input().split())
chess_board = []
max_x = m - 7
max_y = n - 7
res = 1000000000

for i in range(n):
    temp_arr = []

    for c in input():
        temp_arr.append(c)

    chess_board.append(temp_arr)

for i in range(0, max_y):
    for j in range(0, max_x):
        check_board = [row[j:j+8] for row in chess_board[i:i+8]]
        tmp_res = check_diff_min(check_board)
        if res > tmp_res:
            res = tmp_res

print(res)