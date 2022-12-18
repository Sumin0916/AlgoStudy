"""
하늘에서 정의가 빗발친다!
"""

robot_counts = int(input())
robot_info = list()

for i in range(robot_counts):
    x, y, v = map(int, input().split())
    robot_info.append((i + 1, ((x**2 + y**2)**0.5) / v))

robot_info.sort(key=lambda x: x[1])

for ri in robot_info:
    print(ri[0])