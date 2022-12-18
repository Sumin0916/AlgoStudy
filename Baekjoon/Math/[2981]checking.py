def gcd(a, b):
    if a%b == 0:
        return b
    return gcd(b, a%b)

N = int(input())
nums = [int(input()) for _ in range(N)]
nums.sort()
res = set()

ngcd = nums[1]-nums[0]

for i in range(2, N):
    ngcd = gcd(ngcd, nums[i]-nums[i-1])
res.add(ngcd)

for i in range(2, int(ngcd**(0.5))+1):
    if ngcd % i == 0:
        res.add(i)
        res.add(ngcd//i)

res = sorted(list(res))

print(" ".join(list(map(str, res))))
