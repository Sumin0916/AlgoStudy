a, b, c = map(int, input().split())


def abc(a, b):
    if b % 2:
        return abc(a, b-1) * a
    elif b == 0:
        return 1
    elif b == 1:
        return a
    else:
        return abc(a, b//2)**2 % c


print(abc(a, b) % c)
