import sys

n = int(sys.stdin.readline().rstrip())
lst = list()
for _ in range(n):
    lst.append(int(input()))

bus = 1

stack = list()
answer = list()

while lst:
    want = lst.pop(0)
    while True:
        if want >= bus:
            answer.append("+")
            stack.append(bus)
            bus += 1

        else:
            if stack[-1] == want:
                answer.append("-")
                stack.pop()
            else:
                answer.append(0)
            break

    if answer[-1] == 0:
        print("NO")
        break

if answer[-1] != 0:
    for a in answer:
        print(a)
