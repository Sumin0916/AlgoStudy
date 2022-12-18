"""
떡볶이 떡 만들기
"""

def binary_search(array, target, start, end):
    mid = (start+end) // 2
    while True:
        if start > end:
            return None

        mid = (start+end) // 2

        if array[mid] == target:
            return mid
        
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1

n, m = map(int, input().split())
rice_cake = list(map(int, input().split()))

rice_cake.sort()

max_height = rice_cake[n-1]

for h in range(max_height, 0, -1):
    t_ind = binary_search(rice_cake, h, 0, n-1)
    if t_ind != None:
        ind = t_ind
    
    res = sum(list(map(lambda x: x-h, rice_cake[ind:])))

    if res >= m:
        print(h)
        break
    