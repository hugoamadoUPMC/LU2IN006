#CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CFLAGS = -g -Wno-unused-parameter
CC = gcc

PROGRAMS = main

all: $(PROGRAMS)

main: main.o exo2/biblioH.o exo1/biblioLC.o exo1/biblioLC.o exo1/entreeSortieLC.o exo2/entreeSortieH.o
	$(CC) -o $@ $(CFLAGS) $^ -lm

main_comparaison : main_comparaison.o exo2/biblioH.o exo1/biblioLC.o exo1/entreeSortieLC.o exo2/entreeSortieH.o
	$(CC) -o $@ $(CFLAGS) $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f *.o *~ $(PROGRAMS)