from collections import deque

N = int(input())
MAX = 1000001
dp = [[MAX, -1] for _ in range(MAX)]


def graph_search(start):
    queue = deque()
    queue.append(start)
    dp[start][0] = 0
    dp[start][1] = 0
    while queue:
        num = queue.popleft()
        if num == 1:
            break
        if num % 3 == 0:
            n = num//3
            if dp[n][0] > dp[num][0] + 1:
                dp[n][0] = dp[num][0] + 1
                dp[n][1] = num
                queue.append(n)
        if num % 2 == 0:
            n = num // 2
            if dp[n][0] > dp[num][0] + 1:
                dp[n][0] = dp[num][0] + 1
                dp[n][1] = num
                queue.append(n)
        if dp[num-1][0] > dp[num][0] + 1:
            n = num - 1
            dp[n][0] = dp[num][0] + 1
            dp[n][1] = num
            queue.append(n)


def find_path(num):
    if num == 0:
        return ""
    return find_path(dp[num][1]) + " " + str(num)


graph_search(N)
print(dp[1][0])
print(find_path(1)[1:])
