for _ in range(int(input())):
    m, n, b, c = map(int, input().split())
    stat = False
    if b > c:
        m, n = n, m
        b, c = c, b
    ny = c - b
    while ny <= m * n:
        if ny % m == 0:
            print(b + ny)
            stat = True
            break
        ny += n
    if not stat:
        print(-1)
