#!/usr/bin/env python3

def getAndParseInput():
    n = input()
    n = int(n)
    
    if (n <= 0):
        raise IndexError
 
    tbl = list()
    for i in range(n):
        tbl.append(list())
        buff = input()
        if (len(buff) < n):
            raise IndexError
        for j in range (n):
            tbl[i].append(buff[j])
    return (n, tbl)

def simulate(n, tbl):
    for turn in range(n):
        for i in range(n - 1):
            for j in range(n):
                if (tbl[i][j] != '.'):
                    continue
                if (tbl[i + 1][j] == ' '):
                    tbl[i][j] = ' '
                    tbl[i + 1][j] = '.'

def show(n, tbl):
    for i in range(n):
        for j in range(n):
            print(tbl[i][j], end="")
        print("")

def main():
    try:
        n, tbl = getAndParseInput()
    except:
        return
    simulate(n, tbl)
    show(n, tbl)

if (__name__ == "__main__"):
    main()
