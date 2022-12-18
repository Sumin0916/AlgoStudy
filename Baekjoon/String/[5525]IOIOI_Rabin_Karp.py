import sys


input = sys.stdin.readline

n = int(input())
m = int(input())
s = list(map(ord, list(input().rstrip())))
pn_len = 2*n+1
pn = "I"+"OI"*n
want_hash = 0
for i in range(pn_len):
    want_hash += (2 ** i) * ord(pn[i])
now_hash = 0
for i in range(pn_len):
    now_hash += (2 ** i) * s[i]
res = 0
if now_hash == want_hash:
    res += 1
for i in range(pn_len, m):
    now_hash = (now_hash - s[i-(pn_len)])//2 + (s[i] * (2 ** (pn_len-1)))
    if now_hash == want_hash:
        res += 1
        i += 2
print(res)
