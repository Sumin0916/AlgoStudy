"""
부품 찾기
"""

def binary_search(lst, start, end, value):
    if start > end:
        return "no"

    midle = (start+end) // 2
    
    if lst[midle] == value:
        return "yes"

    elif lst[midle] > value:
        return binary_search(lst, start, midle-1, value)
    else:
        return binary_search(lst, midle+1, end, value)

n = int(input())
parts = list(map(int, input().split()))
m = int(input())
estimate_sheet = list(map(int, input().split()))
parts.sort()

for i in range(m):
    print(binary_search(parts, 0, n-1, estimate_sheet[i]), end=" ")