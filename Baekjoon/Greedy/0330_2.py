"""
숫자 카드 게임
"""
arr = []
n, m = list(map(int, input().split()))

for i in range(n):
    arr.append(list(map(int, input().split())))

answer = max(list(map(min, arr)))

print(answer)