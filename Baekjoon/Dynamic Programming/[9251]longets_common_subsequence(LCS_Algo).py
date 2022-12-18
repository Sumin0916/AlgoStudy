first = input()
second = input()
f_len = len(first)
s_len = len(second)
mem = [list(0 for _ in range(f_len+1)) for _ in range(s_len+1)]

for i in range(1, s_len+1):
    for j in range(1, f_len+1):
        if first[j-1] == second[i-1]:
            mem[i][j] = mem[i-1][j-1] + 1
        else:
            mem[i][j] = max(mem[i-1][j], mem[i][j-1])

print(mem[-1][-1])
