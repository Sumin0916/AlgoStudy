def find_nums(ind, now_sum, init_count, count):
    global ans
    if count == init_count:
        if now_sum == S:
            ans += 1
        return

    for i in range(ind, N):
        if not visited[i]:
            visited[i] = True
            find_nums(i+1, now_sum+ary[i], init_count, count+1)
            visited[i] = False

N, S = map(int, input().split())
ary = list(map(int, input().split()))
visited = [False] * (N)
ans = 0

for i in range(1, N+1):
    find_nums(0, 0, i, 0)

print(ans)
