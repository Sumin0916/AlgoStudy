n, m = list(map(int, input().split()))
s = sorted(list(map(int, input().split())))
res = []


def back_tracking():
    if len(res) == m:
        print(' '.join(map(str, res)))
        return

    for i in range(n):
        res.append(s[i])
        back_tracking()
        res.pop()


back_tracking()
