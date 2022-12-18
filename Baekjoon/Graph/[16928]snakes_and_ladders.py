from collections import deque

def bfs(start, end, graph):
    que = deque()
    visited = [False] * (101)
    que.append(start)
    count = 0
    while que:
        temp_que = deque()
        while que:
            node = que.popleft()
            if 0 < node < 101:
                if node == end:
                    return count
                if not visited[node]:
                    if len(graph[node]) == 1:
                        que.extend(graph[node])
                    else:
                        temp_que.extend(graph[node])
                    visited[node] = True
        que = temp_que
        count += 1



nladder, nsnakes = map(int, input().split())
board = [list(x  for x in range(i+1, i+7)) for i in range(101)]

for _ in range(nladder):
    x, y = map(int, input().split())
    board[x] = [y]
for _ in range(nsnakes):
    u, v = map(int, input().split())
    board[u] = [v]

print(bfs(1, 100, board))
