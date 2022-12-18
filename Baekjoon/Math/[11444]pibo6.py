n = int(input())
m = 1000000007


def product_matrix(ary1, ary2):
    l = 2
    res = [list(0 for _ in range(l)) for _ in range(l)]
    for i in range(l):
        for j in range(l):
            for k in range(l):
                res[i][j] += ary2[k][j] * ary1[i][k]
            res[i][j] %= m
    return res


a = [[1, 1], [1, 0]]
ans = [[1, 0], [0, 1]]

if n <= 1:
    print(n)
else:
    while (n > 0):
        if n % 2 == 1:
            ans = product_matrix(ans, a)
        a = product_matrix(a, a)
        n //= 2

    print(ans[0][1])
