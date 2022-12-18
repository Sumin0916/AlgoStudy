"""
ACM 호텔
"""
test_case = int(input())

for i in range(test_case):
    h, w, c = map(int, input().split())

    if (c % h == 0):
        room_num = 100 * h + (c // h)
    else:
        room_num = (c % h) * 100 + (c // h + 1)

    print(room_num)