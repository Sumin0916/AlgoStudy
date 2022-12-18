x1, y1, x2, y2 = map(int, input().split())
x3, y3, x4, y4 = map(int, input().split())

def ccw(x1, x2, x3, y1, y2, y3):
    func = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1)
    if func > 0:
        return 1
    elif func < 0:
        return -1
    else:
        return 0

a1 = ccw(x1, x2, x3, y1, y2, y3)
a2 = ccw(x1, x2, x4, y1, y2, y4)
b1 = ccw(x3, x4, x1, y3, y4, y1)
b2 = ccw(x3, x4, x2, y3, y4, y2)

if a1*a2 <= 0 and b1*b2 <= 0:
    if a1*a2 == 0 and b1*b2 == 0:
        if max(x1, x2) >= min(x3, x4) and max(x3, x4) >= min(x1, x2) and max(y1, y2) >= min(y3, y4) and max(y3, y4) >= min(y1, y2):
            print(1)
        else:
            print(0)
    else:
        print(1)
else:
    print(0)

