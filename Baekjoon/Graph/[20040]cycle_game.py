import sys

input = sys.stdin.readline


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N, M = map(int, input().split())
parent = [x for x in range(N)]
INF = 1e10
res = INF
for i in range(M):
    s, e = map(int, input().split())
    if find_parent(parent, s) != find_parent(parent, e):
        union_parent(parent, s, e)
    else:
        res = min(res, i+1)
if res == INF:
    print(0)
else:
    print(res)
