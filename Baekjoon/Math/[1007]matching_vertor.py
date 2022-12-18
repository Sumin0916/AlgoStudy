import sys
from itertools import combinations
import math

input = sys.stdin.readline

T = int(input())
res = []

for _ in range(T):
    ans = 1e13
    total_sumx = 0
    total_sumy = 0
    N = int(input())
    p_lst = []

    for _ in range(N):
        x, y = map(int, input().split())
        total_sumx += x
        total_sumy += y
        p_lst.append((x, y))
    
    combi_lst = list(combinations(p_lst, int(N/2)))

    for i in range(int(len(combi_lst)/2)):
        x_sum = 0
        y_sum = 0

        for x1, y1 in combi_lst[i]:
            x_sum += x1
            y_sum += y1

        subs_x = total_sumx - x_sum
        subs_y = total_sumy - y_sum

        ans = min(ans, math.sqrt((x_sum-subs_x)**2+(y_sum-subs_y)**2))

    res.append(ans)

for i in res:
    print(i)
