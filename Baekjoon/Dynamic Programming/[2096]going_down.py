import sys

input = sys.stdin.readline
N = int(input())
can_moving = [[0, 1], [0, 1, 2], [1, 2]]
max_res = [[0 for _ in range(3)] for _ in range(2)]
min_res = [[0 for _ in range(3)] for _ in range(2)]

for _ in range(N):
    a, b, c = map(int, input().split())
    max_res[0][0] = max(max_res[1][0], max_res[1][1]) + a
    max_res[0][1] = max(max_res[1][0], max_res[1][1], max_res[1][2]) + b
    max_res[0][2] = max(max_res[1][1], max_res[1][2]) + c

    min_res[0][0] = min(min_res[1][0], min_res[1][1]) + a
    min_res[0][1] = min(min_res[1][0], min_res[1][1], min_res[1][2]) + b
    min_res[0][2] = min(min_res[1][1], min_res[1][2]) + c



    max_res[1][0], max_res[1][1], max_res[1][2] = max_res[0][0], max_res[0][1], max_res[0][2]
    min_res[1][0], min_res[1][1], min_res[1][2] = min_res[0][0], min_res[0][1], min_res[0][2]
    

print(max(max_res[0]), end=" ")
print(min(min_res[0]))
