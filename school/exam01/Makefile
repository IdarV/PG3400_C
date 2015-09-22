CFLAGS=-Wall -g -std='c11'

all: program

dyn: dynarray_usage

dync:
	rm -f dynarray_usage

test: tests/sorting_tests

test_cycle:
	make test
	./tests/sorting_tests
	rm -f tests/sorting_tests

clean:
	rm -f program

cycle:
	make clean
	make all
	./program