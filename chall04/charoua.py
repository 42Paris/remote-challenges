#!/usr/bin/python3

def main():
    size = int(input())
    world = [list(input()) for i in range(size)]
    correct_world = check_world(size, world)
    if correct_world :
        world = sand_fall(world, size)
        for line in world:
            to_print = "".join(c for c in line)
            print(to_print)

def check_world(size, world):
    correct_world = True
    for i in range(size):
        if correct_world:
            if len(world[i]) != size:
                print("map error : wrong length on line " + str(i + 1))
                correct_world = False
            else :
                for c in world[i]:
                    if (correct_world == True) and (c != " ") and (c != "#") and (c != "."):
                        print("map error : wrong character on line " + str(i + 1))
                        correct_world = False
    return correct_world

def sand_fall(world, size):
    i = size - 2
    while i >= 0 :
        j = size - 1
        while j >= 0 :
            if world[i][j] == ".":
                k = i + 1
                while k < size  and world[k][j] == " " :
                    temp = world[k][j]
                    world[k][j] = world[k - 1][j]
                    world[k - 1][j] = temp
                    k += 1
            j -= 1
        i -= 1
    return world

if __name__ == "__main__":
     main()
