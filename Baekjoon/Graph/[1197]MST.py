import sys


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


def kruskal(edge):
    weight = 0
    for i in range(E):
        if find_parent(parent, edge[i][0]) != find_parent(parent, edge[i][1]):
            union_parent(parent, edge[i][0], edge[i][1])
            weight += edge[i][2]
    return weight


input = sys.stdin.readline

V, E = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(E)]
edge.sort(key=lambda x: x[2])
parent = [i for i in range(V+1)]

print(kruskal(edge))
