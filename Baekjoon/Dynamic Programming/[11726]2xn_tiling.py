import sys

sys.setrecursionlimit(10000)
n = int(input())
mem = [-1 for _ in range(n + 1)]

def tiling(n, mem):
    if mem[n] != -1:
        return mem[n]
    if n == 0:
        return 1
    elif n < 0:
        return 0
    mem[n] = tiling(n-1, mem) + tiling(n-2, mem)
    return mem[n]

print(tiling(n, mem) % 10007)
    