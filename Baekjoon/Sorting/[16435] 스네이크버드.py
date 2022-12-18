"""
스네이크버드

코드 길이 : 117B
백준 숏코딩 16순위
"""

a,s=map(int,input().split())
f=list(map(int,input().split()))
f.sort()
for f in f:
    if f<=s:
        s+=1
print(s)