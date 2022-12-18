import sys

n, m = map(int, input().split())
book = {}

for i in range(1, n + 1):
    book[i] = sys.stdin.readline().rstrip()

reverse_book = dict(map(reversed, book.items()))

for _ in range(m):
    order = sys.stdin.readline().rstrip()
    if ord("A") <= ord(order[0]) <= ord("Z"):
        print(reverse_book[order])
    else:
        print(book[int(order)])
