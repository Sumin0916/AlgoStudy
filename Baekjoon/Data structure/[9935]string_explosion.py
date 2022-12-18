string = list(input())
explosion_string = input()
len_string = len(string)
len_ex = len(explosion_string)


stack = []
std = explosion_string[-1]

for c in string:
    stack.append(c)
    if c == std and "".join(stack[-len_ex:]) == explosion_string:
        del stack[-len_ex:]


if stack:
    print("".join(stack))
else:
    print("FRULA")
    

