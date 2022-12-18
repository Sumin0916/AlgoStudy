import sys

T = int(input())


def find_loop(start):
    global visited, student
    stack = [start]
    track = [start]
    visited[start] = True
    while stack:
        now_student = stack.pop()
        next_student = student[now_student]
        if not visited[next_student]:
            stack.append(next_student)
            visited[next_student] = True
            track.append(next_student)
    if track and next_student in track:
        return len(track[track.index(next_student):])
    else:
        return 0


for _ in range(T):
    N = int(input())
    student = [0] + list(map(int, input().split()))
    visited = [False] * (N+1)
    res = 0
    for i in range(1, N+1):
        if not visited[i]:
            res += find_loop(i)
    print(N-res)
