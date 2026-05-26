CC=gcc
CFLAGS=-Wall -Wextra -Werror
EXE=main
SOURCES=src/main.c src/kv.c
OBJECTS=$(SOURCES:.c=.o)
INCLUDES=./inc

all: $(SOURCES) $(EXE)

$(SOURCES):
	$(CC) $(CFLAGS) -I$(INCLUDES) $< -o $@

$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -I$(INCLUDES) $(OBJECTS) -o $(EXE)

clean:
	rm -f *.o $(EXE)
