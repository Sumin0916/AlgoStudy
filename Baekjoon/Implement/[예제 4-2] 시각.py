"""
시각
"""

n = int(input())

h, m, s = 0, 0, 0
count = 0

while not (h == n and m == 59 and s == 59):
    if "3" in str(h) + str(m) + str(s):
        count += 1
    
    s += 1

    if s == 60:
        m += 1
        s = 0
    if m == 60:
        h += 1
        m = 0

print(count)