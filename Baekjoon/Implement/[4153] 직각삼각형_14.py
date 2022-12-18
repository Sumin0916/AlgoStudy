"""
직각삼각형
"""
while True:
    len_lst = list(map(int, input().split()))
    len_lst.sort()
    
    if len_lst[0] == 0:
        break
    
    if (len_lst[0] ** 2) + (len_lst[1] ** 2) == len_lst[2] ** 2:
        print("right")
    
    else:
        print("wrong")