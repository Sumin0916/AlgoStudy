"""
전자레인지
"""
now_temp = int(input())
goal_temp = int(input())
c = int(input())
d = int(input())
e = int(input())

if now_temp > 0:
    res = (goal_temp - now_temp) * e
    print(res)

else:
    res = (abs(now_temp) * c) + d + (goal_temp * e)
    print(res)