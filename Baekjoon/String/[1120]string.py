a, b = input().split()
n = len(b) - len(a) + 1
max = -1
for i in range(n):
    s = 0
    same = 0
    for c in a:
        if c == b[s+i]:
            same += 1
        s += 1
    if max < same:
        max = same
print(len(a) - max)
