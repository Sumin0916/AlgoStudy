import sys

sys.setrecursionlimit(3000)

n = int(input())
palette = []
rg_palette = []


def appreciate(ary, i, j, n, p):
    if i < 0 or i >= n or j < 0 or j >= n:
        return

    pix = ary[i][j]
    if p == pix:
        ary[i][j] = 0
    else:
        return
    appreciate(ary, i + 1, j, n, pix)
    appreciate(ary, i - 1, j, n, pix)
    appreciate(ary, i, j + 1, n, pix)
    appreciate(ary, i, j - 1, n, pix)
    return


for _ in range(n):
    inp = input()
    palette.append(list(inp))
    rg_palette.append(list(inp))

for i in range(n):
    for j in range(n):
        if rg_palette[i][j] == "G":
            rg_palette[i][j] = "R"
res = [0, 0]
for i in range(n):
    for j in range(n):
        if palette[i][j] != 0:
            appreciate(palette, i, j, n, palette[i][j])
            res[0] += 1

for i in range(n):
    for j in range(n):
        if rg_palette[i][j] != 0:
            appreciate(rg_palette, i, j, n, rg_palette[i][j])
            res[1] += 1

print(res[0], res[1])
