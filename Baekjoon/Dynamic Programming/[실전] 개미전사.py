"""
개미 전사
"""

n = int(input())
lst = list(map(int, input().split()))

mem = [0] * 100

mem[0] = lst[0]
mem[1] = max(lst[0], lst[1])

for i in range(2, n):
    mem[i] = max(mem[i - 1], mem[i- 2] + lst[i])

print(mem[n-1])