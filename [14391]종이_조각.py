n, m = map(int, input().split())
paper = [list(x for x in input()) for _ in range(n)]
m_ind = n * m
print(paper)
max_score = -1
visited = 0b0000000000000000

def find_maximum(sum, visited):
    global max_score, n, m
    for i in range(m_ind):
        if not (visited & (1<<i)):
            for w in range(i%m, m):
                if not (visited & (1<<(i+w))):
                    for tw in range(w):
                        visited = visited | (1<<(i+tw))
                        temp_num = "".join(paper[i//m][i%m:i%m+tw+1])
                        find_maximum(sum + int(temp_num), visited)
                    for tw in range(w):
                        visited = visited & ~(1<<(i+tw))
            for h in range(i//m, n):
                if not (visited & (1<<(i+(h*m)))):
                    temp_num = ""
                    for th in range(h):
                        visited = visited | (1<<(i+th*m))
                        temp_num+=paper[i//m+th][i%m]
                        find_maximum(sum + int(temp_num), visited)
                    for th in range(h):
                        visited = visited & ~(1<<(i+th*m))
            return
    max_score = max(max_score, sum)
    return

find_maximum(0, visited)

print(max_score)