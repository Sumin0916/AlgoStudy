import sys

input = sys.stdin.readline

N, M = map(int, input().split())
matrix = [[0 for _ in range(N)] for _ in range(N)]

for _ in range(M):
    a, b = map(int, input().split())
    matrix[a-1][b-1] = 1
    matrix[b-1][a-1] = 1

D = int(input())

def pow(matrix, degree):
    if degree == 1:
        return matrix

    half = pow(matrix, degree//2)
    half_square = product(half, half)

    if degree % 2 == 0:
        return half_square
    else:
        return product(half_square, matrix)

def product(matrix_1, matrix_2):
    length = N
    result = [[0 for _ in range(length)] for _ in range(length)]
    for i in range(length):
        for j in range(length):
            result[i][j] = sum([(matrix_1[i][k] * matrix_2[k][j])%1000000007 for k in range(length)])%1000000007
    return result

res = pow(matrix, D)

print(res[0][0])
