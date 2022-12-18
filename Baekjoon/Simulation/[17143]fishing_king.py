import sys

input = sys.stdin.readline

def movnig_shark(r, c, s, d, z):
    nr, nc, nd = r, c, d
    if d == 1:
        if s < r:
            nr = r - s
        else:
            nr = (s - r) % (2*R - 2)
            if nr >= R:
                nr = 2*R - 2 - nr
            nd = 2 if int((s - r)/(R - 1)) % 2 == 0 else 1
    elif d == 2:
        nr = (r + s) % (2*R - 2)
        if nr >= R:
            nr = 2*R - 2 - nr
        nd = 2 if int((r + s)/(R - 1)) % 2 == 0 else 1
    elif d == 3:
        nc = (c + s) % (2*C - 2)
        if nc >= C:
            nc = 2*C - 2 - nc
        nd = 3 if int((c + s)/(C - 1)) % 2 == 0 else 4
    else:
        if s < c:
            nc = c - s
        else:
            nc = (s - c) % (2*C - 2)
            if nc >= C:
                nc = 2*C - 2 - nc
            nd = 3 if int((s - c)/(C - 1)) % 2 == 0 else 4
    return [nr, nc, s, nd, z]


def fishing():
    global graph

    for i in range(R):
        if graph[i][fishing_king]:
            temp = graph[i][fishing_king][2]
            graph[i][fishing_king] = 0
            return temp
    return 0


def set_graph():
    new = [[0] * C for _ in range(R)]
    lst = []

    for i in range(R):
        for j in range(C):
            if graph[i][j] != 0:
                lst.append([i, j]+graph[i][j])
    for r, c, s, d, z in lst:
        r, c, s, d, z = movnig_shark(r, c, s, d, z)
        if new[r][c] != 0:
            if new[r][c][2] < z:
                new[r][c] = [s, d, z]
        else:
            new[r][c] = [s, d, z]
    return new

R, C, M = map(int, input().split())

shark_info = [list(map(int, input().split())) for i in range(M)]
fishing_king = -1
graph = [[0] * C for _ in range(R)]
ans = 0

for r, c, s, d, z in shark_info:
    graph[r-1][c-1] = [s, d, z]

while fishing_king < C-1:
    fishing_king += 1
    ans += fishing()
    graph = set_graph()

print(ans)



