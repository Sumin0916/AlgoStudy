board = list(input())
board.append(".")
res = []
lenth = 0
for c in board:
    if c == "X":
        lenth += 1
    else:
        if lenth % 2 != 0:
            res = -1
            break
        elif lenth != 0:
            res.append("AAAA"*(lenth//4)+"BB"*((lenth%4)//2))
        lenth = 0
        res.append(".")

if res == -1:
    print(-1)
else:
    res.pop()
    print("".join(res))
