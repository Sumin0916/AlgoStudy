number = input()

now_cal = 1

if len(number) == 1:
    print(number)

else:
    if number[0] == '0':
        now_cal = 0
    for i in range(len(number)):
        if i >= 1 and number[i-1] == '0':
            now_cal += int(number[i])
        else:
            now_cal *= int(number[i])

print(now_cal)