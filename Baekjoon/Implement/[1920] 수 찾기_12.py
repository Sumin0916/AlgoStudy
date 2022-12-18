"""
수 찾기
"""
def binary_search(array, target, start, end):
    if start > end:
        return print("0")

    mid = (start + end) // 2

    if array[mid] == target:
        return print("1")
    
    elif array[mid] > target:
        return binary_search(array, target, start, mid - 1)
    
    else:
        return binary_search(array, target, mid + 1, end)  


n = int(input())
n_ints = list(map(int, input().split()))
n_ints.sort()

m = int(input())
m_list = list(map(int, input().split()))

for i in m_list:
    binary_search(n_ints, i, 0, n-1)