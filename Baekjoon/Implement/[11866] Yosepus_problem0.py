n, k = map(int, input().split())

lst = [x for x in range(1, n+1)]
ind = 0
k -= 1

print("<", end="")

while lst:
    len_n = len(lst)
    ind += k
    if len_n <= ind:
        ind %= len_n
    print(lst.pop(ind), end="")
    if len_n != 1:
        print(", ", end="")

print(">")