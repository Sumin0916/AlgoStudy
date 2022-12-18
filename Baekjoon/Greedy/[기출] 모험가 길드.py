"""
모험가 길드
"""

adv_nums = int(input())
adv_fears = list(map(int, input().split()))

adv_fears.sort()
counter = 0
temp_group = []

while True:
    if adv_fears[0] > len(adv_fears):
        break

    temp_group.append(adv_fears.pop(0))

    if temp_group[-1] == len(temp_group):
        temp_group = []
        counter += 1

print(counter)