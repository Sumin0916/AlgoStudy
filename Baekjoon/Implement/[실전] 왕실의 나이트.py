"""
왕실의 나이트
"""

knight_point = input()

dic = {"a": 1, "b": 2, "c": 3, "d": 4, "e": 5, "f": 6, "g": 7, "h": 8} # ord 함수를 이용하는게 더 효과적인 것 같음.

k_row = int(knight_point[1])
k_col = dic[knight_point[0]]
counter = 0

cal_move = [
    (k_col + 1, k_row - 2), 
    (k_col - 1, k_row - 2), 
    (k_col + 1, k_row + 2), 
    (k_col - 1, k_row + 2), 
    (k_col + 2, k_row + 1), 
    (k_col - 2, k_row + 1), 
    (k_col + 2, k_row - 1), 
    (k_col - 2, k_row - 1)
    ]

for m_point in cal_move:
    if 1 <= m_point[0] <= 8 and 1 <= m_point[1] <= 8:
        counter += 1

print(counter)