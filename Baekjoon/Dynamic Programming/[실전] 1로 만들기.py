"""
1로 만들기
"""

n = int(input())
num_lst = [0] * 30001
i = 2
while True:
    if i == n + 1:
        break
    num_lst[i] = num_lst[i-1] + 1

    if i % 2 == 0:
        num_lst[i] = min(num_lst[i], num_lst[i//2] + 1)
    if i % 3 == 0:
        num_lst[i] = min(num_lst[i], num_lst[i//3] + 1)
    if i % 5 == 0:
        num_lst[i] = min(num_lst[i], num_lst[i//5] + 1)
    i += 1

print(num_lst[n])