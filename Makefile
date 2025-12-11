CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Source files
SRCS = src/main.c src/can_frame.c

# Object files
OBJS = build/main.o build/can_frame.o

# Target executable
TARGET = build/main

# Build everything
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile main.c
build/main.o: src/main.c include/can_frame.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o

# Compile can_frame.c
build/can_frame.o: src/can_frame.c include/can_frame.h
	mkdir -p build
	$(CC) $(CFLAGS) -c src/can_frame.c -o build/can_frame.o

run: $(TARGET)
	$(TARGET)

clean:
	rm -rf build

.PHONY: run clean