import sys
from collections import deque

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    queue = deque()
    N, K = map(int, input().split())
    num_edge = [0 for _ in range(N+1)]
    cost_lst = [0 for _ in range(N+1)]
    order = [list() for _ in range(N+1)]
    time_cost = list(map(int, input().split()))
    res = 0

    for _ in range(K):
        x, y = map(int, input().split())
        num_edge[y] += 1
        order[x].append(y)

    K = int(input())

    for i in range(1, N+1):
        if not num_edge[i]:
            queue.append(i)
            cost_lst[i] += time_cost[i-1]

    while queue:
        node = queue.popleft()
        if node == K:
            break
        for n in order[node]:
            num_edge[n] -= 1
            cost_lst[n] = max(cost_lst[n], time_cost[n-1]+cost_lst[node])
            if num_edge[n] == 0:
                queue.append(n)

    print(cost_lst[K])
