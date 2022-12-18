import sys
import heapq

input = sys.stdin.readline

N, M = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(M)]
edge.sort(key=lambda x: x[2])
parent = [x for x in range(N+1)]
cost = []


def find_parent(node):
    if parent[node] == node:
        return node
    return find_parent(parent[node])


def union_parent(parent, a, b, c):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    elif a > b:
        parent[a] = b
    else:
        return False
    return c


def kruskal_algoritm(parent, edge, cost):
    for a, b, c in edge:
        res = union_parent(parent, a, b, c)
        if res:
            heapq.heappush(cost, -c)
    return -(sum(cost) - cost[0])


print(kruskal_algoritm(parent, edge, cost))
