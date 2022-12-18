"""
백준 1439
"""
num = input()
num_len = len(num)
dif = 0

if num_len == 1:
    print(1)

else:
    for i in range(1, num_len):
        if num[i] != num[i-1]:
            dif += 1

print((dif+1)//2)