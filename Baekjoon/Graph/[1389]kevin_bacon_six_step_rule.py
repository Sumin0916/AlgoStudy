INF = 999999999

n, m = map(int, input().split())
graph = [list() for _ in range(n+1)]
dis = [[INF for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

for i in range(1, n+1):
    for j in graph[i]:
        dis[i][j] = 1


for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j:
                continue
            if i == k or j == k:
                continue
            if dis[i][j] > dis[i][k] + dis[k][j]:
                dis[i][j] = dis[i][k] + dis[k][j]
res = []

for i in range(1, n+1):
    sumit = 0
    for n in dis[i]:
        if n != INF:
            sumit += n
    res.append([sumit, i])
res_1 = min(res, key=lambda x: x[0])
print(res_1[1])
