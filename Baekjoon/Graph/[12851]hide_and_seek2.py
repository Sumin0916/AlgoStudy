from collections import deque


def hide_and_seek(start, end):
    queue = deque()
    queue.append([start, 0])
    res_count = 0
    dp = [1000000 for _ in range(200000)]
    while queue:
        temp = deque()
        while queue:
            point, t = queue.popleft()
            if dp[point] < t:
                continue
            if point == end:
                if dp[point] > t:
                    res_count = 1
                elif dp[point] == t:
                    res_count += 1
            dp[point] = min(dp[point], t)
            if point > K:
                temp.append([point-1, t+1])
            elif point < K:
                if point > 0:
                    temp.append([point-1, t+1])
                temp.append([point+1, t+1])
                if 2 * point >= end:
                    if 2 * point - end + 1 <= end - point:
                        temp.append([point*2, t+1])
                else:
                    if end - 2 * point + 1 <= end - point:
                        temp.append([point*2, t+1])
        queue = temp
    return [dp[end], res_count]


N, K = map(int, input().split())

lst = hide_and_seek(N, K)
print(lst[0])
print(lst[1])
