"""
백준 2748
피보나치 수 2

조건문 한 개도 실행 속도에 적지 않은 영향을 주는 것을 알 수 있었다.
"""


def fibo2(num):
    if num == 0:
        return 0
    if memorization[num]:
        return memorization[num]
    memorization[num] = fibo2(num-1) + fibo2(num-2)
    return memorization[num]


n = int(input())
memorization = [0] * (n+1)
memorization[1:3] = [1, 1]
print(fibo2(n))