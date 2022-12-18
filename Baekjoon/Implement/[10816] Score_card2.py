n = int(input())
n_lst = list(map(int, input().split()))
m = int(input())
m_lst = list(map(int, input().split()))

dic = dict()

for num in n_lst:
    value = dic.get(num)
    if value == None:
        dic[num] = 1
    else:
        dic[num] += 1

for num in m_lst:
    value = dic.get(num)
    if value == None:
        print(0, end="")
    else:
        print(value, end="")
    print(" ", end="")
