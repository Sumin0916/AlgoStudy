def find(num):
    global parent
    if num == parent[num]:
        return num
    return find(parent[num])

def union(a, b):
    n1 = find(a)
    n2 = find(b)
    if n1 > n2:
        parent[n1] = n2
        return n2
    elif n1 <= n2:
        parent[n2] = n1
        return n1

direc = {"D": (1, 0), "U": (-1, 0), "R": (0, 1), "L": (0, -1)}
N, M = map(int, input().split())
parent = [x for x in range(N*M)]
graph = [list(input()) for _ in range(N)]
ans_set = set()
visited = [False] * (N*M)

for i in range(N*M):
    row = i // M
    col = i % M
    dr, dc = direc[graph[row][col]]
    nr, nc = row+dr, col+dc
    res = union(i, (nr*M)+nc)

for i in range(N*M):
    if find(i) not in ans_set:
        ans_set.add(i)

print(len(ans_set))
