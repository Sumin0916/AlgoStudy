string = list(input())

stat = False
i = 0
while i < len(string):
    if stat:
        if string[i] == ">":
            stat = False
        i += 1
        continue
    if string[i] == "<":
        stat = True

    else:
        if string[i] == " ":
            i += 1
            continue
        e = i+1
        while True:
            if e >= len(string):
                break
            if string[e] == " ":
                break
            if string[e] == "<":
                break
            e += 1
        string[i:e] = reversed(string[i:e])
        i = e-1
    i += 1
print("".join(string))
