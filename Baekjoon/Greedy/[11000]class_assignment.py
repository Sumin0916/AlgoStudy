n = int(input())
lst = []
for _ in range(n):
    s, e = map(int, input().split())
    lst.append([s, e-s, e])
lst.sort()
room = []

for s, d, e in lst:
    stat = False
    for i in range(len(room)):
        if s >= room[i]:
            stat = True
            room[i] = e
            continue
    if not stat:
        room.append(e)

print(len(room))

