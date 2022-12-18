import sys

sys.setrecursionlimit(10000)


def white_earthworm(i, j, m, n):
    if 0 <= i < m and 0 <= j < n:
        if ground[i][j] == 0:
            return
        else:
            ground[i][j] = 0
            white_earthworm(i - 1, j, m, n)
            white_earthworm(i + 1, j, m, n)
            white_earthworm(i, j - 1, m, n)
            white_earthworm(i, j + 1, m, n)
    else:
        return


t = int(sys.stdin.readline().rstrip())

for _ in range(t):
    res = 0
    m, n, k = map(int, sys.stdin.readline().rstrip().split())
    ground = list([0 for _ in range(n)] for _ in range(m))
    for _ in range(k):
        i, j = map(int, sys.stdin.readline().rstrip().split())
        ground[i][j] = 1

    for i in range(m):
        for j in range(n):
            if ground[i][j] == 1:
                white_earthworm(i, j, m, n)
                res += 1
    print(res)