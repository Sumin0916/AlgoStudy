from collections import deque

n, k = map(int, input().split())
visited = [0] * 100001


def follow(now, goal):
    global num_set
    if now == goal:
        print(0)
        return
    que = deque()
    que.append(now)
    while que:
        now = que.popleft()
        if now == goal:
            print(visited[now])
            return
        for son in (now-1, now+1, now*2):
            if -1 < son < 100001 and not visited[son]:
                visited[son] = visited[now] + 1
                que.append(son)


follow(n, k)
