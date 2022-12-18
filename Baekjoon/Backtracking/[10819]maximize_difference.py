N = int(input())
lst = list(map(int, input().split()))
max_res = 0
temp_lst = []
visited = [False] * N


def cal_lst(lst):
    res = 0
    for i in range(1, N):
        res += abs(lst[i-1] - lst[i])
    return res


def backtracking(cnt):
    global max_res
    if cnt == N:
        max_res = max(max_res, cal_lst(temp_lst))
        return
    for i in range(N):
        if not visited[i]:
            temp_lst.append(lst[i])
            visited[i] = True
            backtracking(cnt+1)
            temp_lst.pop()
            visited[i] = False


backtracking(0)
print(max_res)
