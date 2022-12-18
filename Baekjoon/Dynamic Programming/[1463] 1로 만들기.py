"""
백준 1463
1로 만들기
Dynamic Programming으로 문제 푸는 연습을 많이 해보자.
"""
INF = 10000000000

n = int(input())
m = [INF] * (n + 1)
m[1] = 0

for i in range(1, n+1):
    m[i] = min(m[i], m[i-1] + 1)
    if i % 2 == 0:
        m[i] = min(m[i], m[i//2] + 1)
    if i % 3 == 0:
        m[i] = min(m[i], m[i//3] + 1)

print(m[n])
