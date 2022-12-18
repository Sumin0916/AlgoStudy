import sys
import heapq

input = sys.stdin.readline

N, K = map(int, input().split())
jewely = []
bag = []
passed_jewly = []
res = 0

for _ in range(N):
    m, v = map(int, input().split())
    heapq.heappush(jewely, [m, v])
for _ in range(K):
    heapq.heappush(bag, int(input()))

for _ in range(K):
    space = heapq.heappop(bag)
    while jewely and jewely[0][0] <= space:
        m, v = heapq.heappop(jewely)
        heapq.heappush(passed_jewly, -v)
    if passed_jewly:
        res += abs(heapq.heappop(passed_jewly))
    elif not jewely:
        break
        
print(res)
