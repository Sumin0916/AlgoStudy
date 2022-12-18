n = int(input())

for _ in range(n):
    stack = []
    string = input()
    stack.append(string[0])
    for c in string[1:]:
        if len(stack) != 0 and stack[-1] == "(" and c == ")":
            stack.pop()
        else:
            stack.append(c)
    if len(stack):
        print("NO")
    else:
        print("YES")
