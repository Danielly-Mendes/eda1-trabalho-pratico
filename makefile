CC := gcc
CFLAGS := -W -Wall -Wshadow -pedantic

all: BIBLIOTECA
	$(CC) $(CFLAGS) main.c funcoes.o -o bin_main

BIBLIOTECA:
	$(CC) $(CFLAGS) -c funcoes.c

run:
	./bin_main

.PHONY: clean
clean:
	rm -f *.o bin_main