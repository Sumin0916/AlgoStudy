"""
암기왕
"""

test_case = int(input())

for _ in range(test_case):
    n1_len = int(input())
    n1 = set(list(map(int, input().split())))
    n2_len = int(input())
    n2 = list(map(int, input().split()))
    n2_set = set(n2)

    cross = n1 & n2_set

    for num in n2:
        if num in cross:
            print(1)
        else:
            print(0)