# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    lsarrazi.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsarrazi <lsarrazi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 17:48:19 by lsarrazi          #+#    #+#              #
#    Updated: 2020/05/05 17:48:19 by lsarrazi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from sys import stdin

N = int(stdin.readline())

lines = []
for line in stdin:
	lines.append(list(line)[0:N])

for i in range(N - 1, -1, -1):
	for j in range(0, N):
		if lines[i][j] == '.':
			k = i
			while k < N - 1:
				below = lines[k + 1]
				tmp = below[j]
				if tmp != ' ': break
				below[j] = '.'
				lines[k][j] = tmp
				k += 1

for i in range(0, N):
	print ''.join(lines[i])
