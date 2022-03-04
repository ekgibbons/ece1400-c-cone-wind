TARGETS = conegeometry windanalysis test

CFLAGS = -Wall -Wconversion -O3 -lm
CC = gcc

all: $(TARGETS)

conegeometry: conegeometry.c
	$(CC) $(CFLAGS) $< -o $@

windanalysis: windanalysis.c
	$(CC) $(CFLAGS) $< -o $@

test: unittests.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf *~ *.o $(TARGETS) auto/
