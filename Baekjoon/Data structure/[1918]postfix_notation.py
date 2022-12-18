formula = input()
cal_order = {"+": 2, "-": 2, "*": 1, "/": 1}
stack = []
res = ""

for c in formula:
    if c.isalpha():
        res += c
    else:
        if c == "(":
            stack.append(c)
        elif c == "*" or c == "/":
            while stack and (stack[-1] == "*" or stack[-1] == "/"):
                res += stack.pop()
            stack.append(c)
        elif c == "+" or c == "-":
            while stack and stack[-1] != "(":
                res += stack.pop()
            stack.append(c)
        elif c == ")":
            while stack and (stack[-1] != "("):
                res += stack.pop()
            stack.pop()

while stack:
    res += stack.pop()

print(res)
