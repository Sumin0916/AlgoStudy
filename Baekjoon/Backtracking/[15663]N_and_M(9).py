n, m = list(map(int, input().split()))
s = sorted(list(map(int, input().split())))
res = []
visited = [False] * n


def back_tracking(depth):
    if depth == m:
        print(" ".join(map(str, res)))
        return
    last = 0
    for i in range(n):
        if not visited[i] and last != s[i]:
            last = s[i]
            visited[i] = True
            res.append(s[i])
            back_tracking(depth+1)
            visited[i] = False
            res.pop()


back_tracking(0)
