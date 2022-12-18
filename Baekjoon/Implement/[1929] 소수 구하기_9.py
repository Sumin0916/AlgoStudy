"""
소수 구하기
"""
m, n = map(int, input().split())

n += 1
num_bool = [True] * n
num_bool[0] = False; num_bool[1] = False
max_num = int(n ** 0.5) + 1

for num in range(2, max_num):
    if num_bool[num]:
        for j in range(num * 2, n, num):
            num_bool[j] = False

for i in range(m, n):
    if  num_bool[i] == True:
        print(i)
