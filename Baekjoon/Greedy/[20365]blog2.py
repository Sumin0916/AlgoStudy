n = int(input())
color = input()

nr = color.count("R")
nb = n - nr
res = [1, 1]
stat = [False, False]

for c in color:
    if not stat[0] and c == "B":
        stat[0] = True
        res[0] += 1
    elif c == "R":
        stat[0] = False
    if not stat[1] and c == "R":
        stat[1] = True
        res[1] += 1
    elif c == "B":
        stat[1] = False

print(min(res))
