import sys
import itertools

input = sys.stdin.readline
N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
direc = [[1, 0], [-1, 0], [0, 1], [0, -1]]
chicken_lst = []
house_lst = []
min_res = 1000000000


for i in range(N):
    for j in range(N):
        if graph[i][j] == 1:
            house_lst.append([i, j])
        elif graph[i][j] == 2:
            chicken_lst.append([i, j])
            graph[i][j] = 0

l_chicken = len(chicken_lst)

combi = list(itertools.combinations(chicken_lst, M))
for chouse in combi:
    res = 0
    for r, c in house_lst:
        dis = 1000000000
        for ri, ci in chouse:
            dis = min(dis, abs(r - ri) + abs(c - ci))
        res += dis
    min_res = min(min_res, res)
print(min_res)

