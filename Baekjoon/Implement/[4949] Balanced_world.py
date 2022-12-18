import sys

while True:
    string = sys.stdin.readline().rstrip()
    if string == ".":
        break
    stack = []
    for c in string:
        if c == "(" or c == "[":
            stack.append(c)
        elif c == ")" or c == "]":
            if len(stack):
                if c == ")" and stack[-1] == "(":
                    stack.pop()
                elif c == "]" and stack[-1] == "[":
                    stack.pop()
                else:
                    stack.append(c)
            else:
                stack.append(c)

    if len(stack):
        print("no")
    else:
        print("yes")
