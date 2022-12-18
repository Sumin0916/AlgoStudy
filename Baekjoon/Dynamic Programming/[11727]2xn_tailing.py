import sys

sys.setrecursionlimit(10000)

n = int(input())
box = [False] * (n + 1)


def tailing(n):
    global box
    if n == 0:
        return 1
    elif n < 0:
        return 0
    if not box[n]:
        box[n] = 2 * tailing(n-2) + tailing(n-1)
        return box[n]
    else:
        return box[n]


print(tailing(n) % 10007)
