n = int(input())
res = 0
while n > 0:
    if n % 5 == 0:
        res += n // 5
        break
    elif n % 2 == 0:
        res += 1
        n -= 2
    else:
        n -= 5
        res += 1
    if n < 0:
        res = -1
        break
print(res)