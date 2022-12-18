"""
위에서 아래로
"""

lst = []

n = int(input())

for _ in range(n):
    lst.append(int(input()))

print(sorted(lst,reverse=True))