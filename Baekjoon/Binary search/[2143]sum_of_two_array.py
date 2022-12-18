from collections import defaultdict

T = int(input())
N = int(input())
a_ary = list(map(int, input().split()))
M = int(input())
b_ary = list(map(int, input().split()))
a_dict = defaultdict(int)
res = 0

for i in range(N):
    s = 0
    for j in range(i, N):
        s += a_ary[j]
        a_dict[s] += 1

for i in range(M):
    s = 0
    for j in range(i, M):
        s += b_ary[j]
        res += a_dict[T-s]

print(res)


