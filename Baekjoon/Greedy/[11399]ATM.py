n = int(input())
lst = list(map(int, input().split()))
lst.sort()
time = 0
time_stack = 0

for t in lst:
    time_stack += t
    time += time_stack

print(time)

