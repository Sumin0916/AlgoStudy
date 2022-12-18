"""
두 배열의 원소 교체
"""

n, k = map(int, input().split())

lsta = list(map(int, input().split()))
lstb = list(map(int, input().split()))

lsta.sort()
lstb.sort(reverse=True)

for i in range(k):
    if lsta[i] >= lstb[i]:
        break
    else:
        lsta[i], lstb[i] = lstb[i], lsta[i]

print(sum(lsta))            