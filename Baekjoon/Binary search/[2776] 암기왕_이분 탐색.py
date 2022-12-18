"""
암기왕 이분 탐색
While 문의 실행속도가 재귀함수보다 빠르다는 것을 알 수 있었음
"""

t = int(input())

def binary_search(array, target, start, end):
    mid = (start+end) // 2
    while True:
        if start > end:
            return 0

        mid = (start+end) // 2

        if array[mid] == target:
            return 1
        
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1

index = 0

for _ in range(t):
    n = int(input())
    n1 = list(map(int, input().split()))
    m = int(input())
    m1 = list(map(int, input().split()))
    n1.sort()

    for i in m1:
        print(binary_search(n1, i, 0, n-1))