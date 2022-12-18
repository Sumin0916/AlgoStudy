import sys

input = sys.stdin.readline

n = int(input())
ropes = [int(input()) for _ in range(n)]
ropes.sort(reverse=True)

maximun = -1

for i in range(len(ropes)):
    can_rift = ropes[i]*(i+1)
    if can_rift > maximun:
        maximun = can_rift

print(maximun)

