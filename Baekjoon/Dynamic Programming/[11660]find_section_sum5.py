import sys

input = sys.stdin.readline

N, M = map(int, input().split())
array = [list(map(int, input().split())) for _ in range(N)]

for i in range(N):
    for j in range(1, N):
        array[i][j] += array[i][j-1]

for i in range(1, N):
    for j in range(N):
        array[i][j] += array[i-1][j]
for j in range(N):
    array[j].insert(0, 0)
array.insert(0, [0] * (N+1))

for i in range(M):
    x1, y1, x2, y2 = map(int, input().split())
    print(array[x2][y2] - array[x1-1][y2] - array[x2][y1-1] + array[x1-1][y1-1])

