FLAGS=-Wall -Wextra -Wno-unused-parameter -Werror -pedantic -std=c99

all: main

reader.o: reader.c reader.h
	gcc -c $(FLAGS) reader.c

main: reader.o main.o
	gcc -o main reader.o main.o -lm


cow:
	cowsay "❤️ C for life ❤️"
