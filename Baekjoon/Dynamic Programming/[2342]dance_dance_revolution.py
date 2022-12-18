*order, void = map(int, input().split())
len_order = len(order)
INF = 1e10

def move(a, b):
    if a == b:
        return 1
    elif a == 0 or b == 0:
        return 2
    elif abs(b-a) % 2 == 0:
        return 4
    else:
        return 3

dp = [list(list(INF for _ in range(5)) for _ in range(5)) for _ in range(len_order)]
dp[0][0][order[0]] = 2
dp[0][order[0]][0] = 2

for i in range(len_order):
    num = order[i]
    for j in range(5):
        for k in range(5):
            if j != k:
                if num != k:
                    dp[i][num][k] = min(dp[i][num][k], dp[i-1][j][k]+move(j, num))
                if num != j:
                    dp[i][j][num] = min(dp[i][j][num], dp[i-1][j][k]+move(k, num))

print(min(dp[len_order-1][order[len_order-1]]))
