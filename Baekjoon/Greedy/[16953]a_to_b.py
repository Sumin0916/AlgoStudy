a, b = map(int, input().split())
res = 0
while True:
    if a > b:
        res = -2
        break
    if a == b:
        break
    lb = b % 10
    if lb % 2 == 0:
        b = b // 2

    elif lb == 1:
        b = b // 10
    else:
        res = -2
        break
    res += 1

print(res+1)
