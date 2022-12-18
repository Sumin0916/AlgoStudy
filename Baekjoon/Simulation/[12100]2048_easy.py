import sys
import copy

input = sys.stdin.readline

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
ans = 0


def moving_line(direc):
    global graph
    if direc == 0:
        for i in range(N):
            ind = 0
            for j in range(1, N):
                if graph[j][i]:
                    temp = graph[j][i]
                    graph[j][i] = 0
                    if graph[ind][i] == 0:
                        graph[ind][i] = temp
                    elif graph[ind][i] == temp:
                        graph[ind][i] = 2 * temp
                        ind += 1
                    else:
                        ind += 1
                        graph[ind][i] = temp
    if direc == 1:
        for i in range(N):
            ind = N-1
            for j in range(N-2, -1, -1):
                if graph[j][i]:
                    temp = graph[j][i]
                    graph[j][i] = 0
                    if graph[ind][i] == 0:
                        graph[ind][i] = temp
                    elif graph[ind][i] == temp:
                        graph[ind][i] = 2 * temp
                        ind -= 1
                    else:
                        ind -= 1
                        graph[ind][i] = temp
    if direc == 2:
        for i in range(N):
            ind = 0
            for j in range(1, N):
                if graph[i][j]:
                    temp = graph[i][j]
                    graph[i][j] = 0
                    if graph[i][ind] == 0:
                        graph[i][ind] = temp
                    elif graph[i][ind] == temp:
                        graph[i][ind] = 2 * temp
                        ind += 1
                    else:
                        ind += 1
                        graph[i][ind] = temp
    if direc == 3:
        for i in range(N):
            ind = N-1
            for j in range(N-2, -1, -1):
                if graph[i][j]:
                    temp = graph[i][j]
                    graph[i][j] = 0
                    if graph[i][ind] == 0:
                        graph[i][ind] = temp
                    elif graph[i][ind] == temp:
                        graph[i][ind] = 2 * temp
                        ind -= 1
                    else:
                        ind -= 1
                        graph[i][ind] = temp


def cal(cnt):
    global graph, ans
    if cnt == 5:
        ans = max(ans, max(list(map(max, graph))))
        return

    temp_graph = copy.deepcopy(graph)
    for i in range(4):
        moving_line(i)
        cal(cnt+1)
        graph = copy.deepcopy(temp_graph)


cal(0)

print(ans)
