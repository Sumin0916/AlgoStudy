"""
수 정렬하기
"""
num_lst = []
number_count = int(input())

for i in range(number_count):
    num_lst.append(int(input()))

num_lst.sort()

for i in num_lst:
    print(i)