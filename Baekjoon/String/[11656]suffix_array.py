string = input()
res = []
for i in range(len(string)):
    res.append(string[i:])
for s in sorted(res):
    print(s)
