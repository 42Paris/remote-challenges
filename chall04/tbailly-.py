#!/usr/local/bin/python3
import sys
import re

def get_file_content():
    if len(sys.argv) != 2:
        raise Exception('Usage: python3 tbailly-.py map')

    try:
        f = open(sys.argv[1], "r")
    except (OSError, IOError):
        raise Exception('Map not found')
    content = f.read()
    return content

def check_map(lines):
    try:
        size = int(lines[0])
        lines.pop(0)

        if size != len(lines):
            raise Exception('wrong number of lines')
        for idx, line in enumerate(lines):
            # Only spaces, dots and hashes are valid, and each line must be {size} characters long
            if not re.search("^(\.|#| ){%i}$"%(size), line):
                raise Exception('line %s is invalid'%(idx))
        return size
    except ValueError:
        raise Exception('Invalid map: wrong map size')
    except Exception as exc:
        raise Exception('Invalid map: ' +  exc.args[0])

def invert_lines_columns(lines, size):
    columns = []
    for i in range(size):
        column = []
        for line in lines:
            column.append(line[i])
        columns.append(column)
    return columns

def print_result(columns, size):
    result = []
    for i in range(size):
        line = []
        for column in columns:
            line.append(column[i])
        result.append(line)
        print(''.join(line))

def main():
    try:
        content = get_file_content()
        lines = content.split('\n')
        size = check_map(lines)
        columns = invert_lines_columns(lines, size)

        # Compute each column
        for idx, column in enumerate(columns):
            shouldstop = False
            while shouldstop == False:
                shouldstop = True
                for element in range(size):
                    if element < size - 1 and column[element] == '.' and column[element + 1] == ' ':
                        shouldstop = False
                        column = column[:element] + [' ', '.'] + column[element + 2:]
            columns[idx] = column
        
        print_result(columns, size)
    except Exception as exc:
        print(exc.args[0])
    except:
        print('Unknown error')
    finally:
        exit()

main()
