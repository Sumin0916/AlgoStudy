"""
나무 자르기
"""
def binary_search(lst, target):
    end = lst[-1]
    start = 1
    while True:
        count = 0
        mid = (start+end) // 2
        if start > end:
            return mid
        
        for i in lst:
            if i > mid:
                count += i - mid
        
        if count < target:
            end = mid - 1
        
        elif count >= target:
            start = mid + 1

tnum, target = map(int, input().split())
t_lst = list(map(int, input().split()))
t_lst.sort()

print(binary_search(t_lst, target))