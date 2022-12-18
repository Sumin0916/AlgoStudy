import sys
from collections import deque

input = sys.stdin.readline
N, M = map(int, input().split())
direc = [[1, 0], [-1, 0], [0, 1], [0, -1]] # 4방향에 해당하는 좌표를 미리 할당함
graph = [list(map(int, list(input().strip()))) for _ in range(N)]

def BFS_algo(row, col): 
	queue = deque()
    queue.append([row, col])
	graph[row][col] = 1
    while queue:
    	now_r, now_c = queue.popleft()
        for r, c in direc:
        	new_r = now_r + r
            new_c = now_c + c
            if 0 <= new_r < N and 0 <= new_c < M:
            	if graph[new_r][new_c] == 0: # 이 줄 덕분에 우리는 방문처리 배열을 만들지 않아도 된다
                	queue.append([new_r, new_c]) graph[new_r][new_c] = 1 # 미리 변경하는 이유는 큐에 중복되는 좌표를 넣지 않기 위해서
    return True


count = 0
for i in range(N):
	for j in range(M):
    	if graph[i][j] == 0: # 새로운 구멍이 발견되면
        	BFS_algo(i, j) # 그 주변 구멍들을 다 매꾸고
            count += 1
print(count)
            