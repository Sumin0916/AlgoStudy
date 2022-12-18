n = int(input())
c_lst = list(map(int, input().split()))
m = int(input())
m_lst = list(map(int, input().split()))
sm_lst = sorted(c_lst)


def binary_search(array, start, end, goal):
    mid = (start+end)//2
    if mid < start:
        return False
    if array[mid] == goal:
        return True
    elif array[mid] > goal:
        return binary_search(array, start, mid-1, goal)
    else:
        return binary_search(array, mid+1, end, goal)


for i in m_lst:
    if binary_search(sm_lst, 0, n-1, i):
        print(1, end=" ")
    else:
        print(0, end=" ")
