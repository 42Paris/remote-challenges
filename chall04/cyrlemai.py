#!/usr/bin/env python3

import re


def play_grid(grid):
    # We will work on a rotated grid, so that the ground is left
    # and the sky is right.
    rotated_grid = rotate_right(grid)

    def play_line(line):
        while True:
            # Make the first sand block fall
            fall_once = re.sub(r'( +)\.', lambda m: '.' + m.group(1), line, 1)
            if fall_once == line:
                return line
            line = fall_once

    # We play all vertical lines
    played_grid = [play_line(line) for line in rotated_grid]
    # We rotate the grid 3 times to the right to turn it left
    # Yeah that's lazy, but whatever!
    grid = rotate_right(rotate_right(rotate_right(played_grid)))
    return grid


def get_grid():
    grid_len = int(input())
    grid = [input() for i in range(grid_len)]
    return grid


def rotate_right(grid):
    rotated = [''.join(l[i] for l in grid[::-1]) for i in range(len(grid))]
    return rotated


def grid_to_str(grid):
    grid_str = "\n".join(grid)
    return grid_str


print(grid_to_str(play_grid(get_grid())))
