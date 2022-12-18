goal = int(input())
num_broken = int(input())

if (num_broken == 0):
    broken_lst = set()
else:
    broken_lst = set(input().split())

button_lst = set(str(i) for i in range(10)) - broken_lst
res = 0

if len(button_lst) != 0:
    while True:
        a = goal + res
        b = goal - res
        goal_u = set(str(a))
        goal_d = set(str(abs(b)))

        if goal_u & button_lst == goal_u and goal_d & button_lst == goal_d:
            res += min(len(str(a)), len(str(b)))
            break

        elif goal_u & button_lst == goal_u:
            res += len(str(a))
            break
        elif goal_d & button_lst == goal_d:
            res += len(str(b))
            break
        res += 1
    print(min(res, abs(goal-100)))

else:
    print(abs(goal-100))
