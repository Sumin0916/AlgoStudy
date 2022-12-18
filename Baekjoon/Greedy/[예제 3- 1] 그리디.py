"""
교재 예제
"""

money_list = [500, 100, 50, 10]
res_change = [0, 0, 0, 0]

unit_len = len(money_list)

balance = int(input("금액 입력: "))
print("\n", end="")

for unit_index in range(unit_len):
    while balance >= money_list[unit_index]:
        balance -= money_list[unit_index]
        res_change[unit_index] += 1

for i in range(unit_len):
    print(f"{money_list[i]}원: {res_change[i]}개") # 파이썬 3.6 이상 버전에서 지원하는 f - string을 사용함.
