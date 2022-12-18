import heapq
import sys

input = sys.stdin.readline
heap = []

n = int(input())
for _ in range(n):
    order = int(input())
    if order != 0:
        if order < 0:
            heapq.heappush(heap, (-order, -1))
        else:
            heapq.heappush(heap, (order, 1))
    else:
        if len(heap) == 0:
            print(0)
        else:
            a, b = heapq.heappop(heap)
            print(a*b)
