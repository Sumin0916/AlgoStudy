"""
1이 될 때까지
"""
res = 0
n, k = list(map(int, input().split()))

while True:
    if n == 1:
        break
    if n % k == 0:
        n /= k
    else:
        n -= 1
    res += 1

print(res)