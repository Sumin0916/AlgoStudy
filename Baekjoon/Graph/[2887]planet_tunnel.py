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


def kruskal():
    weight = 0
    for i in cost_lst:
        a, b = i[1], i[2]
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            weight += i[0]
    return weight

N = int(input())
planet_lst = []
for i in range(N):
    x, y, z = map(int, input().split())
    planet_lst.append([x, y, z, i])

parent = [x for x in range(N)]
cost_lst = []

for i in range(3):
    planet_lst.sort(key=lambda x: x[i])
    for j in range(1, N):
        cost_lst.append([planet_lst[j][i]-planet_lst[j-1][i], planet_lst[j][3], planet_lst[j-1][3]])

cost_lst.sort(key=lambda x:x[0])

print(kruskal())
