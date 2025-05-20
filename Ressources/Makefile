FLAGS=-Wall -Wextra -Wno-unused-parameter -Werror -pedantic -std=c99

all: main

exo1.o: exo1.c exo1.h
	gcc -c $(FLAGS) exo1.c

exo2.o: exo2.c exo2.h
	gcc -c $(FLAGS) exo2.c

main.o: main.c
	gcc -c $(FLAGS) main.c

main: exo1.o exo2.o main.o
	gcc -o main  exo1.o exo2.o main.o -lm

clean:
	rm *.o
	rm main

cow:
	cowsay "❤️ C for life ❤️"