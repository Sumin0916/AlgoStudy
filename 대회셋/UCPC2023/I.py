N, K = map(int, input().split())
arr = list(map(int, input().split()))
res = -987654321
max_ind = arr.index(max(arr))
for i in range(max_ind):
    res = max(res, arr[max_ind]-arr[i]-(K*abs(max_ind-i)))
for i in range(max_ind+1, N):
    res = max(res, arr[max_ind]-arr[i]-(K*abs(max_ind-i)))

print(res)
