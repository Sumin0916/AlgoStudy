import sys


t = int(sys.stdin.readline().rstrip())

for _ in range(t):
    n = int(sys.stdin.readline().rstrip())
    key_set = set()
    closet = {}
    for _ in range(n):
        val, key = sys.stdin.readline().rstrip().split()
        if key in key_set:
            closet[key] += 1
        else:
            closet[key] = 1
            key_set.add(key)
    if (n > 0):
        print(eval("*".join(map(str, map(lambda x: x+1, list(closet.values()))))) - 1)
    else:
        print(0)
