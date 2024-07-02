CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage
LDFLAGS = -lgcov

all: main

main: main.o rpn_calculator.o
	$(CC) $(CFLAGS) -o main main.o rpn_calculator.o $(LDFLAGS)

tests: tests.o rpn_calculator.o
	$(CC) $(CFLAGS) -o tests tests.o rpn_calculator.o $(LDFLAGS)

clean:
	rm -f main tests *.o *.gcno *.gcda *.gcov

.PHONY: all clean
