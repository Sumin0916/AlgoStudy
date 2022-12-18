"""
랜선 자르기
"""
def binary_search(lst, target):
    end = lst[-1]
    start = 1
    mid = (start+end) // 2
    while True:
        count = 0
        mid = (start+end) // 2
        if start > end:
            return mid
        
        for i in lst:
            count += i // mid
        
        if count < target:
            end = mid - 1
        
        elif count >= target:
            start = mid + 1

k, n = map(int, input().split())

lan_len = []
for _ in range(k):
    lan_len.append(int(input()))

lan_len.sort()

print(binary_search(lan_len, n))