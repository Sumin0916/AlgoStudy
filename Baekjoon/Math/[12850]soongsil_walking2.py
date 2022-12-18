D = int(input())

matrix = [
    [0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 0, 1],
    [0, 0, 0, 1, 1, 0, 1, 0],
    [0, 0, 0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 1, 0, 1, 0]
]

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
    length = len(matrix_1)
    result = [[0 for _ in range(length)] for _ in range(length)]
    for i in range(length):
        for j in range(length):
            result[i][j] = sum([(matrix_1[i][k] * matrix_2[k][j])%1000000007 for k in range(length)])%1000000007
    return result

res = pow(matrix, D)

print(res[0][0])
