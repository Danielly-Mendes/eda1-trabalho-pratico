CC := gcc
CFLAGS := -W -Wall -Wshadow -pedantic

all: BIBLIOTECA
	$(CC) $(CFLAGS) main.c funcao.o -o bin_main

BIBLIOTECA:
	$(CC) $(CFLAGS) -c funcao.c

run:
	./bin_main

.PHONY: clean
clean:
	rm -f *.o bin_main