#!/usr/bin/env python3

import sys

class Grid:
	AIR = ' '
	SAND = '.'
	STONE = '#'    
	
	def __init__(self):
		lines = str(sys.stdin.read()).split('\n')
		self.size = int(lines[0])					# save size, not really usefull but why not
		self.grid = [list(x) for x in lines[1:-1]]	# save the lines (except first line) as a 2d array of char

	def update(self):
		is_updated = 0
		for col in range(0, len(self.grid[0]) ):
			for row in range(len(self.grid) - 2, -1, -1):
				if self.grid[row][col] == self.SAND:
					if self.grid[row + 1][col] == self.AIR:
						self.grid[row][col] = self.AIR
						self.grid[row + 1][col] = self.SAND
						is_updated = 1
		return (is_updated)

	def __str__(self):
		return (
			"\n".join(
				["".join(c) for c in self.grid]
			)
		)

grid = Grid()

while True:
	if (grid.update() == 0):
		print(grid)
		exit()
