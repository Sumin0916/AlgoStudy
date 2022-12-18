import sys

input = sys.stdin.readline
t = int(input())

for _ in range(t):
    n = int(input())
    ary = [list(map(int, input().split())) for _ in range(2)]
    if n > 1:
        ary[0][1] += ary[1][0]
        ary[1][1] += ary[0][0]
        for i in range(2, n):
            ary[0][i] += max(ary[1][i-1], ary[1][i-2])
            ary[1][i] += max(ary[0][i-1], ary[0][i-2])
        print(max(ary[0][n-1], ary[1][n-1]))
    else:
        print(max(ary[0][n-1], ary[1][n-1]))


