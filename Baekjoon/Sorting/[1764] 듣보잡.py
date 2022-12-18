"""
듣보잡
"""

nh, ns = map(int, input().split())
nh_set = set()
ns_set = set()

for _ in range(nh):
    nh_set.add(input())

for _ in range(ns):
    ns_set.add(input())

res_lst = sorted(list(nh_set & ns_set))

print(len(res_lst))

for n in res_lst:
    print(n)