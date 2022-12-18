t = int(input())
lst = [[0],
       [1],
       [2, 4, 8, 6],
       [3, 9, 7, 1],
       [4, 6],
       [5],
       [6],
       [7, 9, 3, 1],
       [8, 4, 2, 6],
       [9, 1]]
for _ in range(t):
    a, b = input().split()
    b = int(b)
    a = int(a[-1])
    if not lst[a][b % len(lst[a]) - 1]:
        print(10)
    else:
        print(lst[a][b % len(lst[a]) - 1])

