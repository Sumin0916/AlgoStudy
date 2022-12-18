import sys

paper_len = int(sys.stdin.readline().rstrip())
paper = [list(map(int, input().split())) for _ in range(paper_len)]
answer = [0, 0]


def divide_conquer(array):
    global answer
    len_array = len(array)
    mid = len_array//2
    if len_array == 1:
        if array[0][0] == 1:
            answer[1] += 1
        else:
            answer[0] += 1
        return
    sum_array = sum(map(sum, array))
    if sum_array == len_array ** 2:
        answer[1] += 1
        return
    elif sum_array == 0:
        answer[0] += 1
        return
    # [row[j:j+m] for row in array[i:i+n]]
    divide_conquer([row[:mid] for row in array[:mid]])
    divide_conquer([row[mid:] for row in array[:mid]])
    divide_conquer([row[:mid] for row in array[mid:]])
    divide_conquer([row[mid:] for row in array[mid:]])
    return


divide_conquer(paper)
for a in answer:
    print(a)
