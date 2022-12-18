import sys

input = sys.stdin.readline
X = 1000000007
expected_value = 0


def involution(num, power):
    res = 1
    while power:
        if power & 1:
            res = res * num % X
        num = num * num % X
        power //= 2
    return res


M = int(input())

for _ in range(M):
    N, S = map(int, input().split())
    expected_value += (S * involution(N, X-2) % X)
    expected_value %= X

print(expected_value)
