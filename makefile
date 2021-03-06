CFLAGS=-g -O2 -Wall -pg -g
CC=gcc

PROGRAM_NAME= evolve
OBJS = main.o readwriteppm.o fitness.o population.o evolve.o \
	crossover.o mutate.o

$(PROGRAM_NAME): $(OBJS)
	$(CC) -o $@ $? -lm -pg -g

escher:
	make; make
	./evolve night.ppm ./images/10000.ppm 10000 500 3e-2


clean:
	rm  *.o $(PROGRAM_NAME) *~
