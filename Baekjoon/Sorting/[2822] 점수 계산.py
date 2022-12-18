"""
점수 계산
"""
scores = []

for _ in range(8):
    scores.append(int(input()))
sort_scores = sorted(scores, reverse=True)
min_num = sort_scores[4]
print(sum(sort_scores[:5]))

for i in range(len(scores)):
    if scores[i] >= min_num:
        print(i + 1)