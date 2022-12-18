import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**9)


def postorder(start, end):
    if start > end:
        return
    d = end + 1

    for i in range(start+1, end+1):
        if preorder[start] < preorder[i]:
            d = i
            break
    postorder(start+1, d -1)
    postorder(d, end)
    print(preorder[start])


preorder = []
count = 0
while count <= 10000:
    try:
        preorder.append(int(input()))
    except:
        break
    count += 1

postorder(0, len(preorder)-1)
