#!/usr/bin/env python3

n = int(input())
grid = [list(input()) for _ in range(n)]

for col in range(n):
    nxt = n-1
    for row in reversed(range(n)):
        if grid[row][col] == ".":
            grid[row][col], grid[nxt][col] = " ", "."
            nxt -= 1
        elif grid[row][col] == "#":
            nxt = row-1

for row in grid:
    print("".join(row))
