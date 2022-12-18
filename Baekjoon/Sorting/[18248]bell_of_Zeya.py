from sys import stdin

input = stdin.readline
n, m = map(int, input().split())



lst = list(enumerate(list(map(int, input().split()))))
print(lst)
