"""
학점 계산
"""

grade = input()

if grade[0] == "A":
    grade_num = 4.0
elif grade[0] == "B":
    grade_num = 3.0
elif grade[0] == "C":
    grade_num = 2.0
elif grade[0] == "D":
    grade_num = 1.0
else:
    grade_num = 0.0

if grade_num > 0:
    if grade[1] == "+":
        grade_num += 0.3
    elif grade[1] == "-":
        grade_num -= 0.3

print(grade_num)
