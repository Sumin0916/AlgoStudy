n = int(input())
map_ary = [list(map(int,list(input()))) for _ in range(n)]


def naming_complex(ary, row, col, n):
    global a
    if 0<= row < n and 0 <= col < n:
        if ary[row][col] != 0:
            ary[row][col] = 0
            a += 1
            naming_complex(ary, row + 1, col, n)
            naming_complex(ary, row - 1, col, n)
            naming_complex(ary, row, col + 1, n)
            naming_complex(ary, row, col - 1, n)
        else:
            return
    else:
        return
count = 0
res = []
for i in range(n):
    for j in range(n):
        a = 0
        if map_ary[i][j] == 1:
            naming_complex(map_ary, i, j, n)
            count += 1
            res.append(a)

print(count)
res.sort()
for r in res:
    print(r)

            
