CFLAGS=-Wall -g -O3 -std='c11'
CC=gcc

LIBRARY_NAME=secretCoder
CLIENT_PROGRAM=program.c
OUTPUT=program

all:
	$(CC) $(CLIENT_PROGRAM) $(CFLAGS) -l$(LIBRARY_NAME) -L. -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)