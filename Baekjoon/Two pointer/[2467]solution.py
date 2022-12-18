N = int(input())

lst = list(map(int, input().split()))

p1 = 0
p2 = N-1
min_res = [abs(lst[p1]+lst[p2]), 0, N-1]
while p1 < p2:
    sol = lst[p1] + lst[p2]
    if abs(sol) < min_res[0]:
        min_res[0] = abs(sol)
        min_res[1] = p1
        min_res[2] = p2
    if sol > 0:
        p2 -= 1
    elif sol < 0:
        p1 += 1
    else:
        break

print(lst[min_res[1]], lst[min_res[2]])
