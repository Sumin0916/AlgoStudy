n, m = list(map(int, input().split()))
s = []


def back_tracking(st):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(st, n+1):
        if i not in s:
            s.append(i)
            back_tracking(i+1)
            s.pop()


back_tracking(1)