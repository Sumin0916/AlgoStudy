"""
큰 수의 법칙
"""

n, m, k = list(map(int, input().split()))
num_lst = list(map(int, input().split()))

num_lst.sort()

add_num = (num_lst[-1] * k) + (num_lst[-2])
std_num =  m // (k+1)

res = (std_num * add_num) + (num_lst[-1] * m % (k+1))

print(res)