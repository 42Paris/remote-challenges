#!/usr/bin/python3

import sys

line = input().lstrip()
if not line.isdigit():
	exit("Invalid size : " + line)
size = int(line)
ret = []
for i in range (size):
	line = sys.stdin.readline()
	line = line.replace('\n', '')
	if len(line) != size:
		exit("Invalid line : " + line)
	for c in line:
		if "#. ".find(c) == -1: 
			exit("Invalid character : " + c)
	ret.append(list(line))

for _ in range (size - 1):
	for i in range (size - 1):
		for j in range (size):
			if ret[i][j] == '.' and ret[i + 1][j] == ' ':
				ret[i][j] = ' '
				ret[i + 1][j] = '.'

for i in range (size):
	for j in range (size):
		print(ret[i][j], end='')
	print()
