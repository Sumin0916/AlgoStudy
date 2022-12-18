n = int(input())
drinks = list(map(int, input().split()))
drinks.sort()
print(sum(drinks[:n-1])/2 + drinks[-1])

