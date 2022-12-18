import sys

input = sys.stdin.readline

N = int(input())
time_list = [tuple(map(int, input().rstrip().split())) for _ in range(N)]
time_list.sort(key=lambda x: (x[1], x[0]))

end = 0
count = 0
for s, e in time_list:
    if s >= end:
        count += 1
        end = e

print(count)