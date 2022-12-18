"""
간단한 다익스트라(데이크스트라) 알고리즘
학부 1-1에 정선태 교수님께서 가르쳐주셨다.
"""
import sys

def dijkstraAlgorithm(graph, start):
    start_node = start
    distance[start_node] = 0
    for _ in range(len(graph)-1):
        visited[start_node] = True
        for end_node, weight in graph[start_node]:
            new_weight = distance[start_node] + weight
            if distance[end_node] > new_weight:
                distance[end_node] = new_weight
        for i, _ in enumerate(sorted(distance)):
            if not visited[i]:
                start_node = i
                break
    return distance
        
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
start = int(input())

graph = [[] for i in range(n+1)]
visited = [False] * (n+1)
distance = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

print(dijkstraAlgorithm(graph, start))