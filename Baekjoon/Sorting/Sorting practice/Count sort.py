"""
계수 정렬
"""

lst = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]

box = [0] * (max(lst) + 1)

for i in lst:
    box[i] += 1

for i in range(len(box)):
    for j in range(box[i]):
        print(i,end=" ")
        