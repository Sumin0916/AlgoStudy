n, m = list(map(int, input().split()))
s = sorted(list(map(int, input().split())))
res = []


def back_tracking(depth, ind):
    if depth == m:
        print(" ".join(map(str, res)))
        return
    last = 0
    for i in range(n):
        if last != s[i] and ind <= i:
            last = s[i]
            res.append(s[i])
            back_tracking(depth+1, i)
            res.pop()


back_tracking(0, -1)
