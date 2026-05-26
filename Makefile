CC=gcc
CFLAGS=-Wall -Wextra -Werror
EXE=main
SOURCES=src/main.c src/kv.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(EXE)

$(SOURCES):
	$(CC) $(CFLAGS) $< -o $@

$(EXE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXE)

clean:
	rm -f *.o $(EXE)
