string = input()

chars = []
sum_nums = 0
n_cnount = 0

for c in string:
    if 48 <= ord(c) <= 57:
       sum_nums += int(c)
       n_cnount += 1
    
    else:
        chars.append(ord(c))

chars.sort()
chars = list(map(chr, chars))

if n_cnount != 0:
    print("".join(chars) + str(sum_nums))

else:
    print("".join(chars))