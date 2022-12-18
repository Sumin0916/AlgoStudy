n = int(input())
point_lst = []

for _ in range(n):
    point_lst.append(tuple(map(int, input().split())))

point_lst.sort(key=lambda x: (x[1], x[0]))

for x, y in point_lst:
    print(x, y)
