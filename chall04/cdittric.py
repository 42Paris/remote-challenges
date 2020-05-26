#!/usr/bin/python3

import sys
import fileinput

a = []
for line in fileinput.input():
    if fileinput.isfirstline():
        n = int(line)
        continue
    if len(line) != n + 1:
        exit()
    a.append(line)
if len(a) != n:
    exit()

b = [[' ' for x in range(n)] for y in range(n)]
for x in range(n):
    sandCount = 0
    for y in range(n):
        if a[y][x] == '.':
            sandCount += 1
        elif a[y][x] == '#':
            b[y][x] = '#'
            for i in range(sandCount):
                b[y - i - 1][x] = '.'
            sandCount = 0
    for i in range(sandCount):
        b[y - i][x] = '.'

for line in b:
    print("".join(line))
