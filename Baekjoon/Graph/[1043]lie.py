from collections import deque


def bfs_search():
    global known_set
    queue = deque()
    queue.extend(known_lst)
    while queue:
        player = queue.popleft()
        for party in graph[player]:
            for p in party:
                if p not in known_set:
                    known_set.add(p)
                    queue.append(p)
    return


N, M = map(int, input().split())
num_known, *known_lst = map(int, input().split())
known_set = set(known_lst)
graph = [list() for _ in range(N+1)]
party_lst = []

for _ in range(M):
    num, *party = map(int, input().split())
    party_lst.append(party)
    for player in party:
        graph[player].append(party)

bfs_search()

for party in party_lst:
    for p in party:
        if p in known_set:
            M -= 1
            break

print(M)
