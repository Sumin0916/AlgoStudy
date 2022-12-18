"""
효율적인 화폐 구성
"""
INF = int(1e9)
n, money = map(int, input().split())
monetary_unit = []
mem = [INF] * (money + 1)
mem[0] = 0

for _ in range(n):
    monetary_unit.append(int(input()))

for m in monetary_unit:
    for i in range(m, money+1):
        mem[i] = min(mem[i], mem[i-m] + 1)

if mem[money] == INF:
    print(-1)
else:
    print(mem[money])
print(mem)