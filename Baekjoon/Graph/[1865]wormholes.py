import sys

input = sys.stdin.readline

T = int(input())
INF = 10000000001


def bellmanford(visited, graph, N, start):
    distance = [INF] * (N+1)
    distance[start] = 0
    for i in range(N-1):
        for j in range(1, N+1):
            for e, t in graph[j]:
                if distance[j] + t < distance[e]:
                    distance[e] = distance[j] + t
    for i in range(1, N+1):
        for e, t in graph[i]:
            if distance[i] + t < distance[e]:
                return True
    return False


for _ in range(T):
    N, M, W = map(int, input().split())
    graph = [list() for _ in range(N+1)]
    visited = [False] * (N+1)
    for _ in range(M):
        s, e, t = map(int, input().split())
        graph[s].append([e, t])
        graph[e].append([s, t])
    for _ in range(W):
        s, e, t = map(int, input().split())
        graph[s].append([e, -t])
    res = bellmanford(visited, graph, N, 1)
    if res:
        output = "YES"
    else:
        output = "NO"
    print(output)
