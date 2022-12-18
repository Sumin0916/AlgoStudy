import sys

input = sys.stdin.readline

N = int(input()) - 1
string = list(input())
l_string = len(string)

for _ in range(N):
    nstring = list(input())
    for i in range(l_string):
        if string[i] != "?" and nstring[i] != string[i]:
            string[i] = "?"

print("".join(string), end="")
