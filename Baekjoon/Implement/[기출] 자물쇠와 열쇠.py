import copy
"""
2020 카카오 채용
프로그래머스 60059

모든 테스트 케이스를 통과하지는 못했다..
"""
def check_unlock(key, kx, ky, lock, n, m):
    max_indx = min(n - 1, kx + m)
    max_indy = min(n - 1, ky + m)
    match_count = 0
    goal_match = 0
    for i in range(n):
        goal_match += lock[i].count(0)

    for y in range(ky, max_indy + 1):
        for x in range(kx, max_indx + 1):

            if key[y][x] == 1 and lock[y][x] == 0:
                match_count += 1
    
    if match_count == goal_match:
        return True
    
    else:
        return False

def rotation(key):
    l = len(key)
    temp = copy.deepcopy(key)

    for i in range(l):
        for j in range(l):
            key[l - j - 1][i] = temp[i][j]

    return key

def solution(key, lock):
    n = len(lock)
    m = len(key)

    for _ in range(4):
        for y in range(n):
            for x in range(n):
                if check_unlock(key, x, y, lock, n, m):
                    return True

        key = rotation(key)

    return False

print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))