import sys

input = sys.stdin.readline

N, M = map(int, input().split())
lst = list(map(int, input().split()))
box = [0] * (N + 1)
box[1] = lst[0]
for i in range(2, N):
    box[i] = box[i-1] + lst[i-1]
box[-1] = box[-2] + lst[-1]

for _ in range(M):
    s, e = map(int, input().split())
    print(box[e] - box[s-1])
