#CFLAGS = -g -Wall -Wextra -pedantic -Wno-unused-parameter
CFLAGS = -g -Wno-unused-parameter
CC = gcc

PROGRAMS = main

all: $(PROGRAMS)

main: main.o biblioH.o
	$(CC) -o $@ $(CFLAGS) $^ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f *.o *~ $(PROGRAMS)