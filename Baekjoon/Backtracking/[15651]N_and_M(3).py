n, m = list(map(int, input().split()))
s = []


def back_tracking(st):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(1, n+1):
        s.append(i)
        back_tracking(i)
        s.pop()


back_tracking(1)
