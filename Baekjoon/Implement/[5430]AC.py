import sys
from collections import deque

t = int(sys.stdin.readline().rstrip())


def ac_definition(s, array):
    if len(array):
        if s:
            array.popleft()
        else:
            array.pop()
        return array
    else:
        return 0


for _ in range(t):
    order = sys.stdin.readline().rstrip()
    len_ary = int(sys.stdin.readline().rstrip())
    ary = sys.stdin.readline().rstrip()
    if ary == "[]":
        ary = deque()
    else:
        ary = deque(map(int, ary[1:-1].split(",")))
    stat = True
    for o in order:
        if o == "R":
            stat = not stat
        else:
            ary = ac_definition(stat, ary)
        if ary == 0:
            print("error")
            break
    if ary != 0:
        ary_len = len(ary)
        if stat:
            print("[", end="")
            for i in range(ary_len):
                if i != ary_len - 1:
                    print(ary[i], end=",")
                else:
                    print(ary[i], end="")
            print("]")
        else:
            print("[", end="")
            for i in range(-1, -(ary_len+1), -1):
                if i != -ary_len:
                    print(ary[i], end=",")
                else:
                    print(ary[i], end="")
            print("]")

