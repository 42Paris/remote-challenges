#!/usr/bin/env python3
def error_handler(message):
    print(message)
    exit(1)

def validate_input(line, size):
    for el in line:
      if(len(line) != size):
        error_handler("Invalid line length")
      if el != ' ' and el != '.' and el != '#':
        error_handler("Invalid Input")
    return line

def check_if_done(grid, size):
  for row in range(size):
    for col in range(size):
      if(grid[row][col] == '.' and row + 1 < size):
        if(grid[row + 1][col] == ' '):
          return False
  return True

def main():
    size = input()
    size = int(size) if size.isdigit() and int(size) > 0 else error_handler("Invalid Input")
    grid = []
    for i in range(size):
        grid.append(validate_input(input(), size))
    done = False
    while done == False:
        for row in range(size):
          for col in range(size):
            if(row + 1 < size and grid[row][col] == '.'):
              if(grid[row + 1][col] == ' '):
                grid[row] = grid[row][:col] + ' ' + grid[row][col + 1:]
                grid[row + 1] = grid[row + 1][:col] + '.' + grid[row + 1][col + 1:]
        done = check_if_done(grid, size)
     

    for line in grid:
        print(line)

if __name__ == "__main__":
    main()
