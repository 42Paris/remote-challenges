#!/usr/bin/python3

import sys

def atoi(start, string):
    ret = 0
    while start < len(string) and string[start].isdigit():
        ret = ret * 10 + int(string[start])
        start += 1
    return (ret, start)

def parse_newline(start, string):
    if string[start] != "\n":
        print("Expected a newline")
        sys.exit(1)
    return (start + 1)

def parse_token(start, string):
    if string[start] not in [" ", "#", "."]:
        print("Wrong token")
        sys.exit(1)
    return (string[start], start + 1)

def print_tab(tab, dim):
    for i in range(dim):
        for j in range(dim):
            print(tab[i][j], sep="", end="")
        print("")

def loop(tab, dim):
    updated = 0
    for i in range(dim):
        for j in range(dim):
            if tab[i][j] == '.' and i + 1 < dim and tab[i + 1][j] == ' ':
                tab[i][j] = ' '
                tab[i + 1][j] = '.'
                updated = 1
    if updated == 0:
        print_tab(tab, dim)
        exit(0)
    loop(tab, dim)

parse_str = sys.stdin.read()
(dim, index) = atoi(0, parse_str)
if index == 0:
    print ("No digit to parse at the beginning of input")
    sys.exit(1)
if dim == 0:
    sys.exit(0)
index = parse_newline(index, parse_str)
remaining_chars = len(parse_str[index:])
if remaining_chars != (dim + 1) * dim:
    print("dim is", dim, ": map description should not have", remaining_chars, "characters")
    sys.exit(1)

tab = []
for i in range(dim):
    tab.append([])
    for j in range(dim):
        (ret, index) = parse_token(index, parse_str)
        tab[i].append(ret)
    index = parse_newline(index, parse_str)

loop(tab, dim)
