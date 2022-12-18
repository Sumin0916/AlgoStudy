p1 = list(map(int, input().split()))
p2 = list(map(int, input().split()))

if (p1[0]+p1[1])/2+(p1[2]+p1[3])/2 < (p2[0]+p2[1])/2+(p2[2]+p2[3])/2:
    print("Emma")
elif (p1[0]+p1[1])/2+(p1[2]+p1[3])/2 > (p2[0]+p2[1])/2+(p2[2]+p2[3])/2:
    print("Gunnar")
else:
    print("Tie")
