FLAGS=-Wall -Wextra -Wno-unused-parameter -Werror -pedantic -std=c99

all: main

reader.o: reader.c reader.h
	gcc -c $(FLAGS) reader.c

machine.o: machine.c machine.h
	gcc -c $(FLAGS) machine.c

main: reader.o main.o
	gcc -o main reader.o main.o -lm


cow:
	cowsay "❤️ C for life ❤️"
