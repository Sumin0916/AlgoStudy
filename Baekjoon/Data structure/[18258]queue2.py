from collections import deque
import sys
queue = deque()
input = sys.stdin.readline

N = int(input())

for _ in range(N):
    order = list(input().split())
    if order[0] == "push":
        queue.append(int(order[1]))
    elif order[0] == "pop":
        if len(queue):
            print(queue.popleft())
        else:
            print(-1)
    elif order[0] == "size":
        print(len(queue))
    elif order[0] == "empty":
        if len(queue):
            print(0)
        else:
            print(1)
    elif order[0] == "front":
        if len(queue):
            print(queue[0])
        else:
            print(-1)
    elif order[0] == "back":
        if len(queue):
            print(queue[-1])
        else:
            print(-1)
