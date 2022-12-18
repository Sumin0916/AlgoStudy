N = int(input())
ans = [[" "] * 2 * N for _ in range(N)]


def recursive(row, col, n):
    if n == 3:
        ans[row][col] = "*"
        ans[row+1][col+1] = ans[row+1][col-1] = "*"
        for i in range(-2, 3):
            ans[row+2][col+i] = "*"
    else:
        n //= 2
        recursive(row, col, n)
        recursive(row+n, col-n, n)
        recursive(row+n, col+n, n)


recursive(0, N-1, N)

for r in ans:
    print("".join(r))

