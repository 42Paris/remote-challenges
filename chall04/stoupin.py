#!/usr/bin/python3

def fall_step(map):
    something_moved = False
    for i in range(len(map) - 2, -1, -1):
        row = map[i]
        for j, type in enumerate(row):
            if type == ".":
                below = map[i+1][j]
                if below == " ":
                    # swap cells
                    map[i+1][j], map[i][j] = map[i][j], map[i+1][j]
                    something_moved = True
    return something_moved

size = int(input())
map = [list(input()) for _ in range(size)]

while fall_step(map):
    pass

for row in map:
    print("".join(c for c in row))
