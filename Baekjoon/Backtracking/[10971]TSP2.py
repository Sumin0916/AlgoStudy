import sys

input = sys.stdin.readline

N = int(input())
ary = [list(map(int, input().split())) for _ in range(N)]
min_res = 1e10

def traveling(start, node, cost, cnt):
    global min_res, visited
    if cnt == N:
        if ary[node][start] != 0:
            min_res = min(min_res, cost+ary[node][start])
        return
    for i in range(N):
        if not visited[i] and ary[node][i] != 0 and i != start:
            visited[i] = True
            traveling(start, i, cost+ary[node][i], cnt+1)
            visited[i] = False


for i in range(N):
    visited = [False] * (N)
    visited[i] = True
    traveling(i, i, 0, 1)

print(min_res)


