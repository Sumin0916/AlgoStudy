N = int(input())
sol = list(map(int, input().split()))
sol.sort()

res = 3 * 1e11

for std in range(N-2):
    s = std+1
    e = N-1
    while s < e:
        temp = sol[std]+sol[s]+sol[e]
        if abs(res) > abs(temp):
            res = temp
            ans = [sol[std], sol[s], sol[e]]
        if temp > 0:
            e -= 1
        elif temp < 0:
            s += 1
        else:
            break
    if res == 0:
        break

print(*ans)
