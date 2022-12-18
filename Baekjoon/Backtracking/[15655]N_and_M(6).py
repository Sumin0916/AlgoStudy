n, m = list(map(int, input().split()))
s = sorted(list(map(int, input().split())))
res = []


def back_tracking(st):
    if len(res) == m:
        print(' '.join(map(str, res)))
        return

    for i in range(st, n):
        if s[i] not in res:
            res.append(s[i])
            back_tracking(i+1)
            res.pop()


back_tracking(0)
