N = int(input())
weight = list(list(map(int, input().split())) for _ in range(N))
dp = list([1e10] * (1<<N) for _ in range(N))

def TSP(visited, now_node):
    if (visited == (1<<N)-1):
        if weight[now_node][0]:
            return weight[now_node][0]
        else:
            return int(1e10)

    if dp[now_node][visited] != int(1e10):
        return dp[now_node][visited]

    for next_node in range(1, N):
        if not weight[now_node][next_node]:
            continue
        if visited & (1<<next_node):
            continue
        dp[now_node][visited] = min(dp[now_node][visited], TSP(visited | (1<<next_node), next_node) + weight[now_node][next_node])

    return dp[now_node][visited]

print(TSP(1, 0))
