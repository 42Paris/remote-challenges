#Python 2.7.18rc1
import sys
import string

def swap(x,y):
    x, y = y, x

def get_inputs():
	n = input()
	lines = []
	for _ in range(n):
		lines.append(list(raw_input()))
	return n, lines

def check_inputs(n, lines):
	for line in lines:
		if not len(line) == n:
			print ("All lines must be N-characters long")
			return 0
	return 1

if __name__ == "__main__":
	n, lines = get_inputs()
	if not check_inputs(n, lines):
		exit(-1)
	for _ in range(n):
		for nbline in range(n - 1):
			for nbcol in range(n):
				if lines[nbline][nbcol] == '.' and lines[nbline + 1][nbcol] == ' ':
					tmp = lines[nbline][nbcol]
					lines[nbline][nbcol] = lines[nbline + 1][nbcol]
					lines[nbline + 1][nbcol] = tmp
	for line in lines:
		str1 = ''.join(line)
		print(str1)
