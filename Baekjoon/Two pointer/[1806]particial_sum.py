import sys

input = sys.stdin.readline

N, S = map(int, input().split())
ary = list(map(int, input().split()))

ans = N+1
start = 0
end = 0
sum_it = 0

while True:
    if sum_it >= S:
        ans = min(ans, end - start)
        sum_it -= ary[start]
        start += 1
    elif end == N:
        break
    else:
        sum_it += ary[end]
        end += 1

if ans == N+1:
    print(0)
else:
    print(ans)
