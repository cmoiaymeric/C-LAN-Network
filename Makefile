FLAGS= -Wall -Wextra -Wno-unused-parameter -Werror -pedantic -std=c99

all: main

reader.o: ./src/reader.c ./src/reader.h
	gcc -c $(FLAGS) reader.c

type.o: ./src/type.c ./src/type.h
	gcc -c $(FLAGS) type.c

machine.o: ./src/machine.c ./src/machine.h
	gcc -c $(FLAGS) machine.c

connexion.o: ./src/connexion.c ./src/connexion.h
	gcc -c $(FLAGS) connexion.c

trame.o: ./src/trame.c ./src/trame.h
	gcc -c $(FLAGS) trame.c

reseau.o: ./src/reseau.c ./src/reseau.h
	gcc -c &(FLAGS) reseau.c

main.o: ./src/main.c
	gcc -c $(FLAGS) main.c

main: ./src/reader.o ./src/type.o ./src/machine.o ./src/connexion.o ./src/trame.o ./src/reseau.o ./src/main.o
	gcc -o main ./src/reader.o ./src/type.o ./src/machine.o ./src/connexion.o ./src/trame.o ./src/reseau.o ./src/main.o -lm

clean:
	rm ./src/*.o
	rm ./main

cow:
	cowsay "❤️ C for life ❤️"
