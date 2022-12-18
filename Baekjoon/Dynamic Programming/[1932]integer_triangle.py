import sys
import copy
input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
cgraph = copy.deepcopy(graph)
for i in range(N-1):
    for j in range(i+1):
        graph[i+1][j] = max(graph[i][j]+cgraph[i+1][j], graph[i+1][j])
        graph[i+1][j+1] = max(graph[i][j]+cgraph[i+1][j+1], graph[i+1][j+1])

print(max(graph[-1]))
