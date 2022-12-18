import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().split())
degree = [0] * (N+1)
graph = [list() for _ in range(N+1)]

for _ in range(M):
    lst_len, *lst = map(int, input().split())
    for i in range(1, lst_len):
        a = lst[i]
        b = lst[i-1]
        degree[a] += 1
        graph[b].append(a)

queue = deque()

for i in range(1, N+1):
    if degree[i] == 0:
        queue.append(i)

ans = []

while queue:
    singer = queue.popleft()
    ans.append(singer)
    for s in graph[singer]:
        degree[s] -= 1
        if degree[s] == 0:
            queue.append(s)

if len(ans) != N:
    print(0)
else:
    for i in ans:
        print(i)
