import union_find as uf
import sys


def kruskal(edge):
    weight = 0
    for i in range(E):
        a, b = edge[i][0], edge[i][1]
        if uf.find_parent(parent, a) != uf.find_parent(parent, b):
            uf.union_parent(parent, a, b)
            weight += edge[i][2]
    return weight


input = sys.stdin.readline

V, E = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(E)]
edge.sort(key=lambda x: x[2])
parent = [i for i in range(V+1)]

print(kruskal(edge))
