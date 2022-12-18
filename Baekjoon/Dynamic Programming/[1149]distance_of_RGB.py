import sys

input = sys.stdin.readline
house = int(input())
rgb_lst = list(list(map(int, input().split())) for _ in range(house))

for i in range(1, house):
    rgb_lst[i][0] = min(rgb_lst[i-1][1], rgb_lst[i-1][2]) + rgb_lst[i][0]
    rgb_lst[i][1] = min(rgb_lst[i-1][0], rgb_lst[i-1][2]) + rgb_lst[i][1]
    rgb_lst[i][2] = min(rgb_lst[i-1][0], rgb_lst[i-1][1]) + rgb_lst[i][2]
print(min(rgb_lst[house-1]))