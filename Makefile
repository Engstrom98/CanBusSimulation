CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude


build/main: src/main.c
	mkdir -p build
	${CC} ${CFLAGS} src/main.c -o build/main



run: build/main
	build/main


clean:
	rm -rf build

.PHONY: run clean