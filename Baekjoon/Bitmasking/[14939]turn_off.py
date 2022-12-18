import copy

def turn_stat(row, col):
    global stat
    for dr, dc in p_lst:
        nr = row + dr
        nc = col + dc
        if 0 <= nr < 10 and 0 <= nc < 10:
            stat[nr][nc] = not stat[nr][nc]

p_lst = [(1, 0), (-1, 0), (0, 1), (0, -1), (0, 0)]
graph = [list(input()) for _ in range(10)]
init_stat = [[False for _ in range(10)] for _ in range(10)]
ans = 101

for order in range(100):
    row = order // 10
    col = order % 10
    if graph[row][col] == "O":
        init_stat[row][col] = True

for init in range(1<<10):
    counter = 0
    stat = copy.deepcopy(init_stat)

    for i in range(10):
        if init & (1<<i):
            turn_stat(0, i)
            counter += 1

    for m in range(1, 10):
        for n in range(10):
            if stat[m-1][n]:
                turn_stat(m, n)
                counter += 1

    is_solved = True
    for i in range(10):
        if stat[9][i]:
            is_solved = False
    
    if is_solved:
        ans = min(ans, counter)

print(ans if ans != 101 else -1)
