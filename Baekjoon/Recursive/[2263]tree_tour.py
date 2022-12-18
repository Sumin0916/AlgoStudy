import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**6)
n = int(input())
inorder = list(map(int, input().split()))
postorder = list(map(int, input().split()))

tree = [list() for _ in range(n+1)]
ind = [0] * (n + 1)
for i in range(n):
    ind[inorder[i]] = i


def conv_preorder(l_in, r_in, l_post, r_post):
    if l_in > r_in or l_post > r_post:
        return
    root = postorder[r_post]
    print(root, end=" ")
    std_ind = ind[root]
    left = std_ind - l_in

    conv_preorder(l_in, std_ind - 1, l_post, (l_post + left) - 1)
    conv_preorder(std_ind + 1, r_in, (l_post + left), r_post - 1)


conv_preorder(0, n-1, 0, n-1)
