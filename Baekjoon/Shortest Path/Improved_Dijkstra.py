"""
개선된 다익스트라 알고리즘
노드의 개수가 10,000이 넘어가면 이 방법을 사용해보자..
Big-O(E*logV)
heap 자료구조를 이용하여 선형탐색을 이진 탐색 느낌으로 바꿀 수 있다.
"""

import heapq
import sys

input = sys.stdin.readline
INF = int(1e9)

n, m = map(int, input().split())
start = int(input())

graph = [[] for i in range(n+1)]
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


def dijkstra(start):
    h = []
    distance[start] = 0
    heapq.heappush(h, (distance[start], start))
    while h:
        dist, now_node = heapq.heappop(h)
        if distance[now_node] < dist:
            continue
        
        for i in graph[now_node]:
            weight = dist + i[1]
            
            if weight < distance[i[0]]:
                distance[i[0]] = weight
                heapq.heappush(h, (weight, i[0]))

dijkstra(start)

for i in range(1, n + 1):
    if distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])
