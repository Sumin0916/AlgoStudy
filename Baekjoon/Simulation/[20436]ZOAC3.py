L, R = input().split()
string = input()
key_dict = {"q": (0, 0), "w": (0, 1), "e": (0, 2), "r": (0, 3), "t": (0, 4), "y": (0, 5), "u": (0, 6), "i": (0, 7), "o": (0, 8), "p": (0, 9), 
"a": (1, 0), "s": (1, 1), "d": (1, 2), "f": (1, 3), "g": (1, 4), "h": (1, 5), "j": (1, 6), "k": (1, 7), "l": (1, 8), 
"z": (2, 0), "x": (2, 1), "c": (2, 2), "v": (2, 3), "b": (2, 4), "n": (2, 5), "m": (2, 6), }

left_set = set(["q", "w", "e", "r", "t", "a", "s", "d", "f", "g", "z", "x", "c", "v"])
l_point = key_dict[L]
r_point = key_dict[R]

ans = 0

for s in string:
    s_point = key_dict[s]
    if s in left_set:
        ans += abs(l_point[0]-s_point[0]) + abs(l_point[1]-s_point[1])
        l_point = s_point
    else:
        ans += abs(r_point[0]-s_point[0]) + abs(r_point[1]-s_point[1])
        r_point = s_point
    ans += 1

print(ans)
