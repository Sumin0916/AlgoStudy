"""
백준 18406
"""

score = input()

mid = len(score) // 2
left = list(map(int, score[:mid]))
right = list(map(int, score[mid:]))

if sum(map(int, left)) == sum(map(int, right)):
    print("LUCKY")
else:
    print("READY")