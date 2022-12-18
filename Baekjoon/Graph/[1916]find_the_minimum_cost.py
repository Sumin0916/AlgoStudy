import sys
import heapq
input = sys.stdin.readline

INF = 100000001
N = int(input())
M = int(input())
graph = [list() for _ in range(N+1)]
path_cost = [INF] * (N+1)
heap = []

for _ in range(M):
    s, e, c = map(int, input().split())
    graph[s].append([c, e])

start, end = map(int, input().split())
heapq.heappush(heap, [0, start])
path_cost[start] = 0
while heap:
    cost, node = heapq.heappop(heap)
    if node == end:
        print(cost)
        break
    for c, n in graph[node]:
        if c + path_cost[node] < path_cost[n]:
            path_cost[n] = c + path_cost[node]
            heapq.heappush(heap, [c + path_cost[node], n])
