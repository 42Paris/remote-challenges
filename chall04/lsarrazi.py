#!/usr/bin/env python3

from sys import stdin

N = int(stdin.readline())

lines = []
for line in stdin:
	lines.append(list(line)[0:N])

for i in range(N - 1, -1, -1):
	for j in range(0, N):
		if lines[i][j] == '.':
			k = i
			while k < N - 1 and lines[k + 1][j] == ' ':
				k += 1
			lines[i][j] = ' '
			lines[k][j] = '.'
			
for line in lines:
	print(''.join(line))
	
