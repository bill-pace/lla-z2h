CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=bin/dbview
SOURCES=src/main.c src/kv.c
OBJECTS=$(patsubst src/%.c, obj/%.o, $(SOURCES))
INCLUDES=inc

all: $(TARGET)

$(TARGET): $(OBJECTS)
	[ -d bin ] || mkdir bin
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJECTS) -o $(TARGET)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	rm -f obj/*
	rm -f $(TARGET)
