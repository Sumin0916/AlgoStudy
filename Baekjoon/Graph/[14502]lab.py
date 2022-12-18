import sys
from collections import deque
import copy

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(N)]
direc = [[1, 0], [-1, 0], [0, 1], [0, -1]]
res = 0


def simulate_combination(count):
    global res

    if count == 3:
        simul_graph = copy.deepcopy(graph)
        tqueue = copy.deepcopy(queue)
        simulate_infection(simul_graph, tqueue)
        res = max(res, sum(i.count(0) for i in simul_graph))
        return
    else:
        for i in range(N):
            for j in range(M):
                if graph[i][j] == 0:
                    graph[i][j] = 1
                    simulate_combination(count+1)
                    graph[i][j] = 0


def simulate_infection(tgraph, tqueue):
    while tqueue:
        row, col = tqueue.popleft()
        for r, c in direc:
            nr = row + r
            nc = col + c
            if 0 <= nr < N and 0 <= nc < M and tgraph[nr][nc] == 0:
                tqueue.append([nr, nc])
                tgraph[nr][nc] = 2


queue = deque()
for i in range(N):
    for j in range(M):
        if graph[i][j] == 2:
            queue.append([i, j])

simulate_combination(0)
print(res)

