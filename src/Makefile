FLAGS=-Wall -Wextra -Wno-unused-parameter -Werror -pedantic -std=c99

all: main

reader.o: reader.c reader.h
	gcc -c $(FLAGS) reader.c

machine.o: machine.c machine.h
	gcc -c $(FLAGS) machine.c

main: main.o reader.o
	gcc -o main reader.o main.o -lm

clean:
	rm *.o
	rm main

cow:
	cowsay "❤️ C for life ❤️"
