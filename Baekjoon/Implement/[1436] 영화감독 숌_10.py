"""
영화감독 숌
"""
count = 1
num = 666

n = int(input())

while True:
    if count == n:
        break
    num += 1
    if "666" in str(num):
        count += 1
    
print(num)