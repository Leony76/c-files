# Makefile
CC = gcc
CFLAGS = -Wall -std=c99
OBJ = main.o util.o
EXEC = programa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o: main.c util.h
	$(CC) $(CFLAGS) -c main.c

funcao.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c

clean:
	rm -f $(OBJ) $(EXEC)
