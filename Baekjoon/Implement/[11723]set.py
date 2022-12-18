import sys

m = int(sys.stdin.readline().rstrip())
s = set()
for _ in range(m):
    order = sys.stdin.readline().rstrip()
    if order[:3] == "all":
        s = set(x for x in range(1, 21))
    elif order[:5] == "empty":
        s.clear()
    else:
        order, num = order.split()
        num = int(num)
        
        if order == "add":
            s.add(num)
        elif order == "remove":
            s.discard(num)
        elif order == "check":
            if num in s:
                print(1)
            else:
                print(0)
        elif order == "toggle":
            if num in s:
                s.remove(num)
            else:
                s.add(num)
    
    