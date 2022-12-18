import copy

N = int(input())
cor = list(map(int, input().split()))
list_cor = copy.deepcopy(cor)
list_cor = set(list_cor)
list_cor = list(list_cor)
list_cor.sort()
dic = dict()

for i in range(len(list_cor)):
    if list_cor[i] not in dic:
        dic[list_cor[i]] = i

for n in cor:
    print(dic[n], end=" ")

