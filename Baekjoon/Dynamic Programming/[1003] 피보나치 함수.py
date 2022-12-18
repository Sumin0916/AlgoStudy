"""
백준 1003
피보나치 함수
메모제이션 기법을 활용하였다.
"""


def fibo(n):
    if m[n]:
        return m[n]
    if n == 1:
        return (0, 1)
    elif n == 0:
        return (1, 0)
    else:
        a = fibo(n-1)
        b = fibo(n-2)
        m[n] = (a[0]+b[0], a[1]+b[1])
        return m[n]


t = int(input())

for _ in range(t):
    num = int(input())
    m = [False] * (num + 1)
    nums_lst = fibo(num)
    print(nums_lst[0], nums_lst[1])
