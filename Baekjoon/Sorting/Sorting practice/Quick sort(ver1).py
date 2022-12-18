"""
나만의 퀵 정렬
교재에 나와있는 퀵 정렬이랑 비슷한 수행 속도를 보여준다.
평균 시간 복잡도 Big-O(N*logN)
"""
import time

lst = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]

def quick_sort(lst): # 총 4가지의 경우의 수가 있다.
    if len(lst) <= 1:
        return lst

    pivot = lst[0]
    l = len(lst)
    left = None
    right = None

    for i in range(1, l):
        if lst[i] >= pivot:
            left = i
            break

    for i in range(l-1, 0, -1):
        if lst[i] < pivot:
            right = i
            break

    if left == None:
        return quick_sort(lst[1:])+ [pivot]

    elif right == None:
        return [pivot] + quick_sort(lst[1:])

    else:
        if right < left:
            lst[0], lst[right] = lst[right], lst[0]
            return quick_sort(lst[:right]) + [pivot] + quick_sort(lst[right+1:])

        else:
            lst[left], lst[right] = lst[right], lst[left]
            return quick_sort(lst)

s1 = time.time()
print(quick_sort(lst))
s2 = time.time()
print(s2 - s1)