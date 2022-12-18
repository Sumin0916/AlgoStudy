import sys

input = sys.stdin.readline


def preorder_traversal(node):
    if node != ".":
        print(node, end="")
        preorder_traversal(graph[node][0])
        preorder_traversal(graph[node][1])


def inorder_traversal(node):
    if node != ".":
        inorder_traversal(graph[node][0])
        print(node, end="")
        inorder_traversal(graph[node][1])


def postorder_traversal(node):
    if node != ".":
        postorder_traversal(graph[node][0])
        postorder_traversal(graph[node][1])
        print(node, end="")


N = int(input())
graph = {}
for _ in range(N):
    root, in1, in2 = input().split()
    graph[root] = [in1, in2]

preorder_traversal("A")
print()
inorder_traversal("A")
print()
postorder_traversal("A")
print()
