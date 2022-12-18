L = int(input())
lst = [0] + list(map(int, input().split()))
lst.sort()
n = int(input())

ans = 0

for i in range(L):
    for k in range(lst[i]+1, lst[i+1]):
        for j in range(lst[i]+2, lst[i+1]):
            if k != j:
                if k <= n <= j:
                    ans += 1

print(ans)

