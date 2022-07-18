all:
	gcc -o main biblioteca.c estrutura.c main.c -pthread -lm -mcmodel=medium -g -Werror