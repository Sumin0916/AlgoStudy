t = int(input())
def a(n):
    global r
    if n == 0:
        r += 1
        return
    elif n < 0:
        return
    a(n-1)
    a(n-2)
    a(n-3)
    return
for _ in range(t):
    n = int(input())
    r = 0
    a(n)
    print(r)