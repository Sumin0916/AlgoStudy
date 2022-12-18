"""
소수 찾기
"""
num_lst_len = int(input())
num_lst = list(map(int, input().split()))

max_num = max(num_lst) + 1
lim_num = int(max_num ** 0.5) + 1
count = 0
num_box = [True] * max_num
num_box[0] = False; num_box[1] = False

for num in range(2, lim_num):
    if num_box[num]:
        for i in range(num * 2, max_num, num):
            num_box[i] = False

for num in num_lst:
    if num_box[num]:
        count += 1

print(count)