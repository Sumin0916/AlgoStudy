from itertools import combinations

N, S = map(int, input().split())
ary = list(map(int, input().split()))

left_lst = ary[:N//2]
right_lst = ary[N//2:]
left_sum = {0:1}
right_sum = {0:1}
ans = 0

for i in range(1, len(left_lst)+1):
    for lst in list(combinations(left_lst, i)):
        t = sum(lst)
        if t not in left_sum:
            left_sum[t] = 1
        else:
            left_sum[t] += 1

for i in range(1, len(right_lst)+1):
    for lst in list(combinations(right_lst, i)):
        t = sum(lst)
        if t not in right_sum:
            right_sum[t] = 1
        else:
            right_sum[t] += 1

for i in list(left_sum.keys()):
    if S - i in right_sum:
        ans += left_sum[i] * right_sum[S - i]

for i in range(len(left_lst)):
    left_sum=left_sum+[left_lst[i]+j for j in left_sum]

if S == 0:
    print(ans-1)
else:
    print(ans)
