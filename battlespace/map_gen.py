#!/usr/bin/python

import time
import random
import argparse
import os

random.seed(int(time.time() * 1000000))

class Category :
	def __init__(self, name, pawns = []) :
		self.name = name
		self.pawns = pawns
	def __add__(self, pawn) :
		if (not isinstance(pawn, Pawn)) :
			raise(TypeError)
		if (len(self.pawns) >= 10) :
			raise(Exception)
		return (Category(self.name, self.pawns + [pawn]))
	def __iadd__(self, pawn) :
		self = self + pawn
		return (self)
	def __str__(self) :
		s = 'Category name : ' + self.name + '\n'
		s += 'Pawns :\n'
		for pawn in self.pawns :
			s += str(pawn)
			s += '__________\n'
		return (s)

class Pawn :
	def __init__(self, shape) :
		if (type(shape) != list) :
			raise(TypeError)
		if (not len(shape)) :
			raise(ValueError)
		l = 0
		empty = True
		for i in shape :
			if (type(i) != str) :
				raise(TypeError)
			if ('#' in i) :
				empty = False
			for c in i :
				if (c != '#' and c != '.') :
					raise(ValueError)
			if (len(i) > l) :
				l = len(i)
		if (empty) :
			raise(ValueError)
		for i in range(len(shape)) :
			shape[i] = shape[i] + (l - len(shape[i])) * '.'
		self.shape = shape
	def rot_left(self) :
		l1 = len(self.shape)
		l2 = len(self.shape[0])
		rot = [''] * l2
		for i in range(l2) :
			for j in range(l1) :
				rot[l2 - (i + 1)] += self.shape[j][i]
		return (Pawn(rot))
	def rot_down(self) :
		return (self.rot_left().rot_left())
	def rot_right(self) :
		return (self.rot_left().rot_left().rot_left())
	def	simplify(self) :
		simp = list(self.shape)
		while (not '#' in simp[0]) :
			del(simp[0])
		while (not '#' in simp[-1]) :
			del(simp[-1])
		empty = True
		for i in simp :
			if (i[0] == '#') :
				empty = False
		while (empty) :
			for i in range(len(simp)) :
				simp[i] = simp[i][1:]
				if (simp[i][0] == '#') :
					empty = False
		empty = True
		for i in simp :
			if (i[-1] == '#') :
				empty = False
		while (empty) :
			for i in range(len(simp)) :
				simp[i] = simp[i][0:-1]
				if (simp[i][-1] == '#') :
					empty = False
		return (Pawn(simp))
	def add_random_annex(self) :
		shape = list(self.shape)
		shape = ['.' * len(shape[0])] + shape + ['.' * len(shape[0])]
		for i in range(len(shape)) :
			shape[i] = '.' + shape[i] + '.'
		for j in range(len(shape)) :
			for i in range(len(shape[0])) :
				if shape[j][i] == '#' :
					for i2, j2 in [(i - 1, j - 1), (i, j - 1), \
						(i + 1, j - 1), (i - 1, j), (i + 1, j), \
						(i - 1, j + 1), (i, j + 1), (i + 1, j + 1)] :
						if shape[j2][i2] == '.' :
							shape[j2] = shape[j2][0:i2] + 'o' + \
								shape[j2][i2 + 1:]
		place = 0
		for j in shape :
			for i in j :
				if (i == 'o') :
					place += 1
		place = random.randint(1, place)
		for j in range(len(shape)) :
			for i in range(len(shape[0])) :
				if (shape[j][i] == 'o') :
					place -= 1
					if (place) :
						shape[j] = shape[j][0:i] + '.' + shape[j][i + 1:]
					else :
						shape[j] = shape[j][0:i] + '#' + shape[j][i + 1:]
		return (Pawn(shape).simplify())
	def __str__(self) :
		s = ''
		for line in self.shape :
			s += line + '\n'
		return (s)
		
class Grid :
	rot_f = [
		lambda pawn : pawn.simplify(),
		lambda pawn : pawn.simplify().rot_left(),
		lambda pawn : pawn.simplify().rot_down(),
		lambda pawn : pawn.simplify().rot_right()]
	def __init__(self, category, annex_nb = 1, mine_nb = 1, shield_nb = 1,
		shield_placement = 'random') :
		if (not isinstance(category, Category)) :
			raise(TypeError)
		if (not category.pawns) :
			raise(ValueError)
		self.category = category
		self.annex_nb = annex_nb
		self.mine_nb = mine_nb
		self.shield_nb = shield_nb
		self.shield_placement = shield_placement
		begin = time.time()
		while (not self.fill_grid()) :
			if (time.time() > begin + 5) :
				raise(RuntimeError)
	def is_valid_place(self, pawn, x, y) :
		if (not isinstance(pawn, Pawn) or type(x) != int or type(y) != int) :
			raise(TypeError)
		if (x < 0 or y < 0 or x + len(pawn.shape[0]) > 10 or \
			y + len(pawn.shape) > 10) :
			return (False)
		for p in self.pawns + self.mines :
			if (p != pawn and hasattr(p, 'x') and \
				not p.x > x + len(pawn.shape[0]) and \
				not x > p.x + len(p.shape[0]) and \
				not p.y > y + len(pawn.shape) and \
				not y > p.y + len(p.shape)) :
				for j in range(len(pawn.shape)) :
					for i in range(len(pawn.shape[0])) :
						if (pawn.shape[j][i] == '#') :
							for j2 in range(len(p.shape)) :
								for i2 in range(len(p.shape[0])) :
									if (p.shape[j2][i2] == '#' and \
										abs((i + x) - (i2 + p.x)) < 2 and \
										abs((j + y) - (j2 + p.y)) < 2) :
										return (False)
		return (True)
	def	get_valid_places(self, pawn) :
		if (not isinstance(pawn, Pawn)) :
			raise(TypeError)
		valid = []
		for j in range(11 - len(pawn.shape)) :
			for i in range(11 - len(pawn.shape[0])) :
				if (self.is_valid_place(pawn, i, j)) :
					valid += [(i, j)]
		return (valid)
	def place(self, pawn) :
		if (not isinstance(pawn, Pawn)) :
			raise(TypeError)
		valid = self.get_valid_places(pawn)
		if (not valid) :
			return (False)
		place = random.randint(0, len(valid) - 1)
		pawn.x = valid[place][0]
		pawn.y = valid[place][1]
		if (pawn in self.pawns) :
			index = '0123456789'[self.pawns.index(pawn)]
		elif (pawn in self.mines) :
			index = 'M'
		else :
			raise(ValueError)
		for j in range(len(pawn.shape)) :
			for i in range(len(pawn.shape[0])) :
				if (pawn.shape[j][i] == '#') :
					self.grid[pawn.y + j] = self.grid[pawn.y + j][0:pawn.x + \
						i] + index + self.grid[pawn.y + j][pawn.x + i + 1:]
		return (True)
	def shield_protection_nb(self, x, y) :
		count = 0
		for j in range(y - 2, y + 3) :
			for i in range(x - 2, x + 3) :
				if (j >= 0 and j < 10 and i >= 0 and i < 10 and
					(j != y or i != x) and self.grid[j][i] != '.' and
					self.grid[j][i] != 'S') :
						count += 1
		return (count)
	def place_shield_max(self) :
		nmax = -1
		max_places = []
		for j in range(10) :
			for i in range(10) :
				if (self.grid[j][i] == '.') :
					ret = self.shield_protection_nb(i, j)
					if (ret > nmax) :
						nmax = ret
						max_places = []
					if (ret == nmax) :
						max_places += [(i, j)]
		if (not max_places) :
			raise(Exception)
		return (max_places[random.randint(0, len(max_places) - 1)])
	def place_shield_min(self) :
		nmin = 0
		min_places = []
		for j in range(10) :
			for i in range(10) :
				if (self.grid[j][i] == '.') :
					ret = self.shield_protection_nb(i, j)
					if (ret > 0 and (ret < nmin or nmin == 0)) :
						nmin = ret
						min_places = []
					if (ret == nmin) :
						min_places += [(i, j)]
		if (not min_places) :
			raise(Exception)
		return (min_places[random.randint(0, len(min_places) - 1)])
	def place_shield_random(self) :
		only_zero = True
		places = []
		for j in range(10) :
			for i in range(10) :
				if (self.grid[j][i] == '.') :
					ret = self.shield_protection_nb(i, j)
					if (only_zero and ret > 0) :
						only_zero = False
						places = []
					if (only_zero or ret > 0) :
						places += [(i, j)]
		if (not places) :
			raise(Exception)
		return (places[random.randint(0, len(places) - 1)])
	def	place_shield(self) :
		if (self.shield_placement == 'random') :
			i, j = self.place_shield_random()
		elif (self.shield_placement == 'min') :
			i, j = self.place_shield_min()
		elif (self.shield_placement == 'max') :
			i, j = self.place_shield_max()
		else :
			raise(Exception)
		self.shields += [(i, j)]
		self.grid[j] = self.grid[j][0:i] + 'S' + self.grid[j][i + 1:]
	def fill_grid(self) :
		self.pawns = []
		for pawn in self.category.pawns :
			self.pawns += [self.rot_f[random.randint(0, 3)](pawn)]
		annex_nb = self.annex_nb
		while (annex_nb > 0) :
			i = random.randint(0, len(self.pawns) - 1)
			self.pawns[i] = self.pawns[i].add_random_annex()
			annex_nb -= 1
		mine_nb = self.mine_nb
		self.mines = []
		while (mine_nb > 0) :
			self.mines += [Pawn(['#'])]
			mine_nb -= 1
		self.grid = ['.' * 10] * 10
		for pawn in self.pawns + self.mines :
			if (not self.place(pawn)) :
					return (False)
		self.shields = []
		shield_nb = self.shield_nb
		while (shield_nb > 0) :
			self.place_shield()
			shield_nb -= 1
		return (True)
	def __str__(self) :
		s = ''
		for j in self.grid :
			for i in j :
				s += ' ' + i
			s += '\n'
		return (s)

armies = {}

armies['nation'] = Category('nation')
armies['nation'] += Pawn(['#####'])
armies['nation'] += Pawn(['####'])
armies['nation'] += Pawn(['###'])
armies['nation'] += Pawn(['###'])
armies['nation'] += Pawn(['##'])

armies['mercenaries'] = Category('mercenaries')
armies['mercenaries'] += Pawn(['.#.', '###', '.#.'])
armies['mercenaries'] += Pawn(['##', '##'])
armies['mercenaries'] += Pawn(['###'])
armies['mercenaries'] += Pawn(['###'])
armies['mercenaries'] += Pawn(['##'])

armies['aliens'] = Category('aliens')
armies['aliens'] += Pawn(['#...', '.###', '#...'])
armies['aliens'] += Pawn(['.#.', '#.#', '.#.'])
armies['aliens'] += Pawn(['#..', '.#.', '..#'])
armies['aliens'] += Pawn(['#..', '.#.', '..#'])
armies['aliens'] += Pawn(['##'])

parser = argparse.ArgumentParser()
parser.add_argument('-a', '--army', choices = list(armies),
	default = list(armies)[random.randint(0, len(armies) - 1)],
	help = 'Select the army to place on the map. If not precised, ' +
	'a random one is selected')
parser.add_argument('-d', '--describe', action = 'store_true',
	help = 'Describe armies')
parser.add_argument('-x', '--annex_number', type = int, default = 1,
	help = 'Select the number of annexes. 1 if not precised')
parser.add_argument('-m', '--mine_number', type = int, default = 1,
	help = 'Select the number of mines. 1 if not precised')
parser.add_argument('-s', '--shield_number', type = int, default = 1,
	help = 'Select the number of shield generators. 1 if not precised')
parser.add_argument('-p', '--shield_placement',
	choices = ['random', 'min', 'max'], default = 'random',
	help = 'Select the way the shields are placed. ' +
	'If not precised, random is selected')

args = parser.parse_args()
if (args.describe) :
	for i in armies :
		print(armies[i])
else :
	grid = Grid(armies[args.army], args.annex_number, args.mine_number,
		args.shield_number, args.shield_placement)
	os.write(1, str(grid))
