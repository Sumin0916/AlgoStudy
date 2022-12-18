import sys
import heapq

input = sys.stdin.readline

N = int(input())
M = int(input())
INF = 10000000000
graph = [list() for _ in range(N+1)]
dis = [[INF, i] for i in range(N+1)]


def dijkstra_algo(start, end):
    heap = []
    dis[start][0] = 0
    heapq.heappush(heap, [0, start])
    while heap:
        cost, node = heapq.heappop(heap)
        if cost > dis[node][0]:
            continue
        for v, c in graph[node]:
            if c + dis[node][0] < dis[v][0]:
                dis[v][0] = c + dis[node][0]
                dis[v][1] = node
                heapq.heappush(heap, [dis[v][0], v])
    return dis[end]


def find_path(node):
    path.append(node)
    if node == start:
        return
    find_path(dis[node][1])


for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
start, end = map(int, input().split())

path = []
res = dijkstra_algo(start, end)
find_path(end)

print(res[0])
print(len(path))
print(*path[::-1])
