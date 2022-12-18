"""
방번호
"""

count_num = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
res = 0

num = input()

for n in num:
    n = int(n)
    count_num[n] += 1

cal_nine_six = (count_num[6]+count_num[9]) // 2 + (count_num[6]+count_num[9]) % 2
count_num.append(cal_nine_six)
count_num[6] = 0
count_num[9] = 0

res = max(count_num)

print(res)