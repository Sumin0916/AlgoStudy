n, m = map(int, input().split())
res = []


def try_back(order):
    if order == m:
        print(" ".join(map(str, res)))
        return
    for i in range(1, n+1):
        if i not in res:
            res.append(i)
            try_back(order+1)
            res.pop()


try_back(0)
