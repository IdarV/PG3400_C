# show all warnings, compile with C11 standard, optimize the compiling with O2
# cudos til Tomas som hjalp meg med makefiles

CFLAGS=-Wall -g -O3 -std='c11'
INC=../inc
CFILES=$(wildcard *.c)
OBJECTS=$(CFILES:.c=.o)

.c.o:
	gcc $(CFLAGS) -I$(INC) -c $<

all: program

program: $(OBJECTS)
	gcc $(CFLAGS) -I$(INC) $^ -o $@

clean:
	rm -f program
	rm -f *.o
