import sys
import heapq

input = sys.stdin.readline

N = int(input())
array = []
for _ in range(N):
    order = int(input())
    if order:
        heapq.heappush(array, (-order, order))
    else:
        if len(array) == 0:
            print(0)
        else:
            print(heapq.heappop(array)[1])
