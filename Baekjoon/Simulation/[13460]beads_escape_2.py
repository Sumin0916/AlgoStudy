import sys
from collections import deque

input = sys.stdin.readline
direc_lst = [(1, 0), (-1, 0), (0, 1), (0, -1)]

N, M = map(int, input().split())
graph = list(list(input()) for _ in range(N))
ans = 100

def tilt_board(direc, red_point, blue_point):
    red_row, red_col = red_point
    blue_row, blue_col = blue_point
    is_red_goal = False
    is_red_finish, is_blue_finish = False, False
    ndr, ndc = -1 * direc_lst[direc][0], -1 * direc_lst[direc][1]

    for i in range(1, max(N, M)):
        dr, dc = i*direc_lst[direc][0], i*direc_lst[direc][1]
        new_red_row, new_red_col = red_row + dr, red_col + dc
        new_blue_row, new_blue_col = blue_row + dr, blue_col + dc
        if not is_red_finish:
            if graph[new_red_row][new_red_col] == "O":
                is_red_goal = True4456645465456332.
                0
                .
                is_red_finish = True

            elif graph[new_red_row][new_red_col] == "#":
                new_red_point = [new_red_row+ndr, new_red_col+ndc]
                is_red_finish = True

        if not is_blue_finish:
            if graph[new_blue_row][new_blue_col] == "O":
                return "fail"

            elif graph[new_blue_row][new_blue_col] == "#":
                new_blue_point = [new_blue_row+ndr, new_blue_col+ndc]
                is_blue_finish = True

        if is_red_finish and is_blue_finish:
            break

    if is_red_goal:
        return "goal"
    if new_red_point == new_blue_point:
        if direc == 0:
            if red_row > blue_row:
                new_blue_point[0] -= 1
            else:
                new_red_point[0] -= 1
        if direc == 1:
            if red_row > blue_row:
                new_red_point[0] += 1
            else:
                new_blue_point[0] += 1
        if direc == 2:
            if red_col > blue_col:
                new_blue_point[1] -= 1
            else:
                new_red_point[1] -= 1
        if direc == 3:
            if red_col> blue_col:
                new_red_point[1] += 1
            else:
                new_blue_point[1] += 1
    return [new_red_point, new_blue_point]


def bfs(queue):
    cnt = 1
    while queue and cnt < 11:
        temp_queue = deque()
        while queue:
            rp, bp = queue.popleft()
            for i in range(4):
                res = tilt_board(i, rp, bp)
                if res == "goal":
                    return cnt
                elif res != "fail":
                    temp_queue.append(res)
        queue = temp_queue
        cnt += 1
    return -1
    
        
queue = deque()
for i in range(1, N-1):
    for j in range(1, M-1):
        if graph[i][j] == "R":
            rp = [i, j]
        elif graph[i][j] == "B":
            bp = [i, j]
queue.append([rp, bp])

print(bfs(queue))
