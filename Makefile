CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/data_structures.c
OBJ = build/main.o build/data_structures.o

build/program: $(OBJ)
	$(CC) $(OBJ) -o build/program

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*

