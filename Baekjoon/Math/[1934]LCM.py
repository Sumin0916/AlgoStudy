def euclidean_algorithm(a, b):
    r = -1
    while r != 0:
        r = a % b
        a, b = b, r
    return a

T = int(input())
res = []

for _ in range(T):
    a, b = map(int, input().split())
    res.append(str((a*b)//euclidean_algorithm(a, b)))

print("\n".join(res))