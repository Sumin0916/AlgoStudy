import sys

input = sys.stdin.readline

N = int(input())
star_dict = {}
for i in range(1, N+1):
    star_dict[i] = list(map(float, input().split()))
edge = []
lst = []
parent = [x for x in range(N+1)]


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


def combi(ind, cnt):
    if cnt == 2:
        if lst[0] != lst[1]:
            s1 = star_dict[lst[0]]
            s2 = star_dict[lst[1]]
            dis = (abs(s1[0]-s2[0])**2+abs(s1[1]-s2[1])**2) ** (0.5)
            edge.append([lst[0], lst[1], dis])
        return
    for i in range(ind, N+1):
        lst.append(i)
        combi(ind+1, cnt+1)
        lst.pop()


combi(1, 0)
E = len(edge)
edge.sort(key=lambda x: x[2])
print("{:.2f}".format(kruskal(edge)))