def main():
    N = int(input())
    if N == 1:
        print(0)
        return 0
    box = [True] * (N+1)
    box[:2] = [False, False]
    std = int(N**(0.5))+1

    for i in range(2, std):
        if box[i]:
            for j in range(2*i, N+1, i):
                box[j] = False

    prime_num = [x for x in range(2, N+1) if box[x]]
    lp = len(prime_num)
    dp = [0 for _ in range(lp)]
    dp[0] = prime_num[0]

    for i in range(1, lp):
        dp[i] += dp[i-1] + prime_num[i]

    p1 = -1
    p2 = 0
    res = 0

    while p1 < p2 and p2 < lp:
        if p1 == -1:
            temp = dp[p2]
        else:
            temp = dp[p2]-dp[p1]

        if temp > N:
            p1 += 1
        elif temp < N:
            p2 += 1
        else:
            res += 1
            p1 += 1
            p2 += 1

    print(res)
    return 0

main()

