E, S, M = map(int, input().split())
ans = (28*19*13*E+15*19*17*S+15*28*10*M)%(15*28*19)
if ans == 0:
    print(7980)
else:
    print(ans)
