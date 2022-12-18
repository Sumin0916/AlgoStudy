def count_trailing_zeros(N):
    # 1.
    cache = [-1] * (N+1)

    def count_factors(n, f):
        # 2.
        if cache[n] != -1:
            return cache[n]

        # 3.
        cache[n] = count_factors(n // f, f) + 1 if not n % f else 0
        return cache[n]

    # 4.
    ans = 0
    for i in range(1, N+1):
        ans += count_factors(i, 5)
    return ans

n = int(input())
print(count_trailing_zeros(n))