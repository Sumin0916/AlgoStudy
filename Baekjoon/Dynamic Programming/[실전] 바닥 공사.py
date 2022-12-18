"""
바닥 공사
Bottom-Up을 이용해서도 완성해 보자.
"""
n = int(input())
ground = [0] * (n)

def construct(ground, num):
    length = len(ground)
    if length == 0:
        num += 1
        return num
    if length >= 2:
        return construct(ground[2:], num+1) + construct(ground[1:], num)
    return construct(ground[1:], num)

res = construct(ground, 0)
print(res)