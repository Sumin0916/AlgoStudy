import sys

input = sys.stdin.readline

N, B = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(N)]


def matrix_product(a, b):
    res = [list(0 for _ in range(N)) for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                res[i][j] += a[i][k]*b[k][j]
            res[i][j] %= 1000
    return res


def divide_and_conquer(a, count):
    if count == 1:
        for i in range(N):
            for j in range(N):
                a[i][j] %= 1000
        return a
    elif count % 2 == 1:
        mat = divide_and_conquer(a, count-1)
        return matrix_product(a, mat)
    else:
        mat = divide_and_conquer(a, count//2)
        return matrix_product(mat, mat)


ans = divide_and_conquer(matrix, B)

for i in ans:
    print(*i)

