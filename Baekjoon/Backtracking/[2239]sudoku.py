def check_validity(row, col):
    box_row = row // 3
    box_col = col // 3
    return [n for n in range(1, 10) if (check_row[row][n] and check_col[col][n] and check_box[box_row*3+box_col][n])]


def solve_sudoku(order):
    global isEnd, len_balnk, graph
    if isEnd:
        return

    if order == len_blank:
        isEnd = True
        for line in graph:
            for n in line:
                print(n, end="")
            print()
        return True
    row, col = blank_lst[order]
    for n in check_validity(row, col):
        graph[row][col] = n
        check_row[row][n] = False
        check_col[col][n] = False
        check_box[(row//3)*3+(col//3)][n] = False
        solve_sudoku(order+1)
        graph[row][col] = 0
        check_row[row][n] = True
        check_col[col][n] = True
        check_box[(row//3)*3+(col//3)][n] = True
    return

            

graph = []
check_row = [list(True for _ in range(10)) for _ in range(9)]
check_col = [list(True for _ in range(10)) for _ in range(9)]
check_box = [list(True for _ in range(10)) for _ in range(9)]
blank_lst = []
isEnd = False
for i in range(9):
    temp = list(map(int, list(input())))
    graph.append(temp)
    for j in range(9):
        num = temp[j]
        if num:
            check_row[i][num] = False
            check_col[j][num] = False
            check_box[(i//3)*3+(j//3)][num] = False
        else:
            blank_lst.append([i, j])
len_blank = len(blank_lst)
solve_sudoku(0)
