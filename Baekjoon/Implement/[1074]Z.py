"""
완벽하게 혼자 풀지 못했다.
"""

N, r, c = map(int, input().split())
res = 0


def z(n, x, y):
    global res
    if x == r and y == c:
        print(int(res))
        return

    if n == 1:
        res += 1
        return

    if not (x <= r < x + n and y <= c < y + n):
        res += n * n
        return
    z(n / 2, x, y)
    z(n / 2, x, y + n / 2)
    z(n / 2, x + n / 2, y)
    z(n / 2, x + n / 2, y + n / 2)


z(2**N, 0, 0)
