#!/usr/bin/env python3
# Tested with Python3.5.3

import sys
import array

grid_size = int()
lines = list()

try:
    
    # Reading the grid size
    grid_size = int(sys.stdin.readline())
    
    # Reading all lines
    line = sys.stdin.readline()
    while (line):
        # Checking the size of each line
        if (len(line) - 1) != grid_size:
            raise Exception("Line wrongly sized")
        # checking invalid chars
        if (line.count('#') + line.count('.') + line.count(' ') != grid_size):
            raise Exception("Wrong character")
        # Adding the line
        lines.append(bytearray(line.encode('ascii')));
        # Checking the line count
        if (len(lines) > grid_size):
            raise Exception("Too many lines")
        # next line
        line = sys.stdin.readline()
    # checking if we have enough lines
    if (len(lines) != grid_size):
        raise Exception("not enough lines")
    
    running = True
    while running:
        # Moving the sand
        running = False
        for y in range(grid_size - 1, -1, -1):
            for x in range(0, grid_size):
                if y < (grid_size - 1) and lines[y][x] == ord('.') and lines[y + 1][x] == ord(' '):
                    running = True
                    lines[y][x] = ord(' ')
                    lines[y + 1][x] = ord('.')
   
    # Display final result:
    for item in lines:
        line = item.decode('ascii')
        print(line, end = '')

    sys.exit(0)
except ValueError:
    print("Error: Wrong size")
except Exception as ex:
    print("ERROR: " + str(ex))
#    sys.exit(1)
