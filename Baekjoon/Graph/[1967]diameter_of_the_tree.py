import sys

input = sys.stdin.readline

N = int(input())
INF = 10000001
graph = [list() for _ in range(N+1)]
res = -1
for _ in range(N-1):
    a, b, w = map(int, input().split())
    graph[a].append([b, w])
    graph[b].append([a, w])


def dfs(start):
    global res
    stack = [[start, 0]]
    visit = [False for _ in range(N+1)]
    visit[start] = True
    max_node = 0
    while stack:
        node, weight = stack.pop()
        if res < weight:
            res = weight
            max_node = node
        for n, w in graph[node]:
            if not visit[n]:
                stack.append([n, weight + w])
                visit[n] = True
    return [max_node, res]


print(dfs(dfs(1)[0])[1])
