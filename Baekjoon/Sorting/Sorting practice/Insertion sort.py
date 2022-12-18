"""
삽입 정렬
시간 복잡도 Big-O(N**2)
그러나 일반적으로 선택 정렬보다 빠르다.
"""

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
    for j in range(i):
        if array[j] > array[i]:
            array.insert(j,array.pop(i))

print(array)