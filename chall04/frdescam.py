#!/usr/bin/env python3

def apply_gravity(matrix, width, x, y) :
    while y < width - 1 and matrix[y + 1][x] == ' ' :
        matrix[y][x] = ' '
        matrix[y + 1][x] = '.'
        y = y + 1

def get_matrix_final_state(matrix, width) :
    for x in range(width) :
        for y in range(width - 1, -1, -1) :
            if matrix[y][x] == '.' :
                apply_gravity(matrix, width, x, y)
    return matrix

def print_matrix(matrix, width) :
    for i in range(width) :
        for j in range(width) :
            print(matrix[i][j], end='')
        print("")

def main() :
    # Get map from stdin
    width = int(input())
    matrix = []
    for i in range(width):
        matrix.append(list(input()))
    final_matrix = get_matrix_final_state(matrix, width)
    print_matrix(final_matrix, width)

if __name__ == "__main__":
    main()
