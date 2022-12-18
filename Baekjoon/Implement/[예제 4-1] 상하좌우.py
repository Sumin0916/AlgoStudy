"""
상하좌우
"""

space_size = int(input())
move_orders = list(input().split())

player_point = [1, 1]

for order in move_orders:
    if order == "U":
        if player_point[0] != 1:
            player_point[0] -= 1
    elif order == "D":
        if player_point[0] != space_size:
            player_point[0] += 1
    elif order == "R":
        if player_point[1] != space_size:
            player_point[1] += 1
    elif order == "L":
        if player_point[1] != 1:
            player_point[1] -= 1

for p in player_point:
    print(p, end=" ")