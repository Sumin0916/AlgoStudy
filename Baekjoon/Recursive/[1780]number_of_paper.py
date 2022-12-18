import sys

input = sys.stdin.readline

N = int(input())
paper = [list(map(int, input().rstrip().split())) for _ in range(N)]
result = [0, 0, 0]


def cuting_paper(paper):
    global result
    paper_len = len(paper)
    if paper_len == 1:
        result[paper[0][0]] += 1
        return
    temp = paper[0][0]
    paper_type = paper[0][0]
    for i in range(paper_len):
        for j in range(paper_len):
            if temp != paper[i][j]:
                paper_type = None
                break
        if paper_type is None:
            break
            temp = paper[i][j]
    if paper_type == 1:
        result[1] += 1
        return
    elif paper_type == -1:
        result[-1] += 1
        return
    elif paper_type == 0:
        result[0] += 1
        return
    cut = paper_len//3
    cuted_paper = [[paper[i][:cut] for i in range(cut)],
                   [paper[i][cut:2*cut] for i in range(cut)],
                   [paper[i][2*cut:] for i in range(cut)],
                   [paper[i][:cut] for i in range(cut, 2*cut)],
                   [paper[i][cut:2*cut] for i in range(cut, 2*cut)],
                   [paper[i][2*cut:] for i in range(cut, 2*cut)],
                   [paper[i][:cut] for i in range(2*cut, paper_len)],
                   [paper[i][cut:2*cut] for i in range(2*cut, paper_len)],
                   [paper[i][2*cut:] for i in range(2*cut, paper_len)]]
    for i in range(9):
        cuting_paper(cuted_paper[i])
    return


cuting_paper(paper)

print(f"{result[2]}\n{result[0]}\n{result[1]}")


