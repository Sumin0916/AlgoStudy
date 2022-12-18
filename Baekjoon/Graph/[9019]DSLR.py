import sys
from collections import deque

input = sys.stdin.readline
mod = 1000


def bfs(start, goal):
    queue = deque()
    queue.append([start, ""])
    num_set.add(start)
    while queue:
        num, order = queue.popleft()
        dt = (num*2) % 10000
        if dt == goal: return order+"D"
        if dt not in num_set:
            num_set.add(dt)
            queue.append([dt, order+"D"])
        st = num - 1 if num != 0 else 9999
        if st == goal: return order+"S"
        if st not in num_set:
            num_set.add(st)
            queue.append([st, order+"S"])
        lt = ((num % mod)*10) + (num // mod)
        if lt == goal: return order+"L"
        if lt not in num_set:
            num_set.add(lt)
            queue.append([lt, order+"L"])
        rt = ((num % 10) * mod) + (num // 10)
        if rt == goal: return order+"R"
        if rt not in num_set:
            num_set.add(rt)
            queue.append([rt, order+"R"])


for _ in range(int(input())):
    initial_num, goal = map(int, input().split())
    num_set = set()
    print(bfs(initial_num, goal))
