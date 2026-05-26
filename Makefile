CC=gcc
CFLAGS=-Wall -Wextra -Werror
TARGET=bin/dbview
SOURCES=src/main.c src/kv.c
OBJECTS=$(patsubst src/%.c, obj/%.o, $(SOURCES))
INCLUDES=inc

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJECTS) -o $(TARGET)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) $< -o $@

clean:
	rm -f *.o $(TARGET)
