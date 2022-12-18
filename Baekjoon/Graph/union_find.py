def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

"""
경로 압축 find
"""

def find_parent(parent, x):
    if parent[x] == x:
        return x
    return parent[x] = find_parent(parent[x])


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b
