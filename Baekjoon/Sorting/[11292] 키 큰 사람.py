"""
키 큰 사람
"""

while True:
    test_case = int(input())
    if test_case == 0:
        break

    class_room = []

    for _ in range(test_case):
        name, length = input().split(" ")
        length = float(length)
        class_room.append([name, length])
    class_room.sort(key=lambda x: x[1], reverse=True)
    
    for i in range(test_case):
        if class_room[i][1] == class_room[0][1]:
            print(class_room[i][0], end=" ")