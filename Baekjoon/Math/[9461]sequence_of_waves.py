T = int(input())
lst = [0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9]
lst.extend([0 for _ in range(90)])
for i in range(11, 101):
    lst[i] = lst[i-1] + lst[i-5]
for _ in range(T):
    print(lst[int(input())])
