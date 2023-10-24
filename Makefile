CC = gcc

CFLAGS = -O3
WARNINGS = -Wall -Wconversion

LIBS = -lm

OBJS = conefuncs.o
INCS = linalg.h

all: conegeometry windanalysis test

debug: CFLAGS += -DDEBUG -g
debug: all

# compile windanalysis
windanalysis: windanalysis.o
	$(CC) $(WARNINGS) $(CFLAGS) $< -o $@ $(LIBS)

# compile conegeometry
conegeometry: conegeometry.o $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

# compile tests
test: unittests.o $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.c $(INCS)
	$(CC) -c -o $@ $< $(CFLAGS) $(WARNINGS)


.PHONY: clean
clean:
	rm -rf *~ *.o test conegeometry windanalysis auto/ *.dSYM
