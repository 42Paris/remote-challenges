#! /usr/bin/python3

def rotate_map(mymap, size):
	out = []
	counter = 0
	while (counter < size):
		tmp = ""
		for i in mymap:
			tmp += i[counter] 
		out.append(tmp)
		counter += 1 
	return (out)

def move(mymap, size):
	out = []
	for line in mymap:
		line = list(line)
		for n, char in enumerate(line[::-1]):
			if (char == "."):
				index = size - n - 1
				for i in range(index + 1, size):
					if (line[i] == " "):
						line[i] = "."
						line[i - 1] = " "
					elif (line[i] == "#"):
						break
		out.append("".join(line))
	return (out)

def show_map(mymap):
	for i in mymap:
		print(i)

def main() :
	size = int(input("gimme map size\n"))
	mymap = []
	
	for i in range(size):
		mymap.append(input())
	
	mymap = rotate_map(mymap, size)
	mymap = move(mymap, size)
	mymap = rotate_map(mymap, size)
	show_map(mymap)

if __name__ == "__main__":
    main()
