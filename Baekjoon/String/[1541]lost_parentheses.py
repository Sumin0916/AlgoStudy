string = input().split("-")
sum_all = 0
for c in string[0].split("+"):
    sum_all += int(c)
for c in string[1:]:
    for j in c.split("+"):
        sum_all -= int(j)

print(sum_all)

