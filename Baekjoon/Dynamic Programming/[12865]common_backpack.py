import sys

input = sys.stdin.readline

N, K = map(int, input().split())
mem = [list(0 for _ in range(K+1)) for _ in range(N)]

objects = [list(map(int, input().split())) for _ in range(N)]

for i in range(N):
    w, v = objects[i]
    for j in range(1, K+1):
        if i == 0:
            if j >= w:
                mem[i][j] = v
        else:
            if j - w >= 0 and mem[i-1][j - w] + v > mem[i-1][j]:
                mem[i][j] = mem[i-1][j - w] + v
            else:
                mem[i][j] = mem[i-1][j]

print(mem[-1][-1])
