N = int(input())
screen = [list(map(int, list(input()))) for _ in range(N)]
res = []


def zip_screen(array, N):
    sum_all = sum(map(sum, array))
    if sum_all == 0:
        return "0"
    elif sum_all == N ** 2:
        return "1"
    else:
        mid = N//2
        p1 = [array[i][:mid] for i in range(mid)]
        p2 = [array[i][mid:] for i in range(mid)]
        p3 = [array[i][:mid] for i in range(mid, N)]
        p4 = [array[i][mid:] for i in range(mid, N)]
        return "(" + zip_screen(p1, mid) + zip_screen(p2, mid) + zip_screen(p3, mid) + zip_screen(p4, mid) + ")"


print(zip_screen(screen, N))
