#!/bin/bash

session=jun2020
norminette=~/.norminette/norminette.rb

if [ ! -e grids/$session ]
then
	mkdir grids/$session
	./map_gen.py -a nation -p min > grids/$session/grid_nn
	./map_gen.py -a nation -p max > grids/$session/grid_nx
	./map_gen.py -a mercenaries -p min > grids/$session/grid_mn
	./map_gen.py -a mercenaries -p max > grids/$session/grid_mx
	./map_gen.py -a aliens -p min > grids/$session/grid_an
	./map_gen.py -a aliens -p max > grids/$session/grid_ax
fi

normtest()
{
	echo "Norm test:"
	if [ -n "$($norminette $(find $1 -name "*.[ch]") | grep Error:)" ]
	then
		echo KO
		return 1
	fi
	echo OK
	return 0
}

makefiletest()
{
	echo "Makefile test:"
	if ! make fclean -C $1 >/dev/null 2>/dev/null
	then
		echo "Error make fclean"
		echo KO
		return 1
	fi
	if [ -e $1/btsp ]
	then
		echo "fclean doesn't remove btsp"
		echo KO
		return 1
	fi
	if ! make -C $1 >/dev/null 2>/dev/null
	then
		echo "Error make all"
		echo KO
		return 1
	fi
	if [ ! -e $1/btsp ]
	then
		echo "btsp doesn't exist after make"
		echo KO
		return 1
	fi
	echo OK
	return 0
}

forbiddenfunctionstest()
{
	for i in $(echo $(nm -u $1/btsp) | tr ' ' '\n' | grep GLIBC | cut -d '@' -f1 | grep -v "^_")
	do
		if [ -v $(grep $i <<< "read write malloc free gettimeofday rand srand") ] 2>/dev/null
		then
			echo KO
			return 1
		fi
	done
	return 0
}

gridstest()
{
	total=0
	for i in grids/$session/*
	do echo $i
	score=$(./battlespace $i $1/btsp)
	echo $score
	if [ "$(echo $score | grep "^[ [:digit:] ]*$")" ] && [ "$(echo $total | grep "^[ [:digit:] ]*$")" ]
	then
		: $((total += score))
	else
		total="INVALID"
	fi
	done
	echo "total: $total"
}

test()
{
	if [ -v $(find $1 -name "*.[ch]") ] 2>/dev/null
	then
		echo 'No file matching with pattern "*.[ch]"'
		return
	fi
	if ! normtest $1
	then
		return
	fi
	if ! makefiletest $1
	then
		return
	fi
	if ! forbiddenfunctionstest $1
	then
		return
	fi
	gcc battlespace.c -o battlespace
	gridstest $1
}

mkdir -p results/$session

for i in rendus/$session/*
do
	test $i > results/$session/${i##*/}
done

