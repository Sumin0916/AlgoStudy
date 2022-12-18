import sys

input = sys.stdin.readline
sys.setrecursionlimit(100000)

def find_parent(x):
    if parent[x] == x:
        return x
    parent[x] = find_parent(parent[x])
    return parent[x]
    

G = int(input())
P = int(input())
parent = [x for x in range(G+1)]
ans = 0

for i in range(P):
    gi = int(input())
    k = find_parent(gi)
    if k == 0:
        break
    parent[k] = k-1
    ans += 1

print(ans)
