import sys
import heapq


input = sys.stdin.readline
T = int(input())

for _ in range(T):
    K = int(input())
    box = [False] * (K + 1)
    min_heap = []
    max_heap = []
    for identity in range(1, K + 1):
        order = list(input().rstrip().split())
        order[1] = int(order[1])
        if order[0] == "I":
            num = order[1]
            heapq.heappush(min_heap, (num, identity))
            heapq.heappush(max_heap, (-num, identity))
            box[identity] = num
        elif order[1] == 1:  # 최댓값 삭제
            while max_heap and not box[max_heap[0][1]]:
                heapq.heappop(max_heap)
            if max_heap:
                del_i = max_heap[0][1]
                heapq.heappop(max_heap)
                box[del_i] = False
        else:  # 최솟값 삭제
            while min_heap and not box[min_heap[0][1]]:
                heapq.heappop(min_heap)
            if min_heap:
                del_i = min_heap[0][1]
                heapq.heappop(min_heap)
                box[del_i] = False
    while min_heap and not box[min_heap[0][1]]:heapq.heappop(min_heap)
    while max_heap and not box[max_heap[0][1]]:heapq.heappop(max_heap)
    if min_heap:
        print(-max_heap[0][0], min_heap[0][0])
    else:
        print("EMPYT")