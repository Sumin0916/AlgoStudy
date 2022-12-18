"""
성적이 낮은 순서로 학생 출력하기
"""

n = int(input())

lst = []

for _ in range(n):
    a, b = input().split()
    lst.append((a, int(b)))

lst.sort(key=lambda x: x[1])

for i in range(n):
    print(lst[i][0], end=" ")