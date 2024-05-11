import math

def judge_circle(x1, y1, r1, x2, y2, r2):
    l = find_len(x1, y1, x2, y2)
    if r1+r2 < l:
        return False
    return True

def find_len(x1, y1, x2, y2):
    return math.sqrt(abs(math.pow((x2-x1),2) + math.pow((y2-y1),2)))

def find_belt(lenth, r1, r2):
    if lenth == 0 or (r1+r2) >= lenth:
        return 0

    if r1 > r2:
        r2, r1 = r1, r2
    elif r1 == r2:
        return (2*math.pi*r1) + (2*lenth)

    x = math.sqrt(abs(math.pow(lenth, 2)-math.pow(r2-r1, 2)))

    theta = math.asin(x/lenth)
    dp = 2*math.pi
    return (dp*r2-(dp*r2*(2*theta/(dp)))) + dp*r1-(dp*r1*(2*(math.pi-theta)/(dp))) + (2*x)

def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N = int(input())
gears = [list(map(int, input().split())) for _ in range(N)]
gset = [i for i in range(N)]
gear_set = set()

for i in range(N):
    x1, y1, r1 = gears[i]
    for j in range(i+1, N):
        x2, y2, r2 = gears[j]
        if judge_circle(x1, y1, r1, x2, y2, r2) and gset[j] == j:
            gset[j] = i

for i in gset:
    gear_set.add(i)

set_len = len(gear_set)
set_numbers = list(gear_set)
gearset = [[] for _ in range(N)]
weight_arr = []
for i in range(N):
    gearset[gset[i]].append(i)

for i in range(set_len):
    for j in range(i+1, set_len):
        seta = set_numbers[i]
        setb = set_numbers[j]
        min_cost = 987654321

        for k in gearset[seta]:
            for p in gearset[setb]:
                x1, y1, r1 = gears[k]
                x2, y2, r2 = gears[p]
                fl = find_len(x1, y1, x2, y2)
                min_cost = min(min_cost, find_belt(fl, r1, r2))

        weight_arr.append([seta, setb, min_cost])

ans = 0
parent = [i for i in range(N+1)]
weight_arr.sort(key=lambda x:x[2])
for start, end, weight in weight_arr:
    if find(start) != find(end):
        union(start, end)
        ans += weight

print(ans)