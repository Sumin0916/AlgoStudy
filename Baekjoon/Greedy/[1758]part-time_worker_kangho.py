import sys

input = sys.stdin.readline
n = int(input())
lst = [int(input()) for _ in range(n)]
lst.sort(reverse=True)
res = 0

for i in range(n):
    tip = lst[i] - i
    if tip < 0:
        break
    res += tip

print(res)
