"""
큰 수의 법칙 2
"""

n, m, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

std_adder = k * arr[n-1] + arr[n-2]

res = (std_adder * (m // (k + 1))) + (arr[n-1] * (m % (k + 1)))

print(res)