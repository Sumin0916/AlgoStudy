import sys

input = sys.stdin.readline
N = int(input())
lst1 = []
lst2 = []
for _ in range(N):
    a, b = map(int, input().split())
    lst1.append(a)
    lst2.append(b)
lst1.append(lst1[0])
lst2.append(lst2[0])
s1 = 0
s2 = 0

for i in range(1, N+1):
    s1 += lst2[i] * lst1[i-1]
    s2 += lst1[i] * lst2[i-1]
s = abs(s1-s2) * (0.5)
print("{:.1f}".format(s))
