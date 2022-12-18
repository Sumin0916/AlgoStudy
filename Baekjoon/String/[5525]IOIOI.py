n = int(input())
s_len = int(input())
s = list(input())
res = 0
ind = 0
p_n = "I" + ("OI" * n)
p_n_len = 2*n + 1

while True:
    if ind >= s_len - (p_n_len - 1):
        break
    if s[ind] == "O":
        ind += 1
        continue
    elif s[ind] == "I":
        if "".join(s[ind:ind+p_n_len]) == p_n:
            ind += 2
            res += 1
            continue
    ind += 1

print(res)

