  # the compiler: gcc for C program, define as g++ for C++
CC = gcc

  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

  # the build target executable:
default: cars

cars: main.o car.o neighbor.o
	$(CC) $(CFLAGS) -o cars main.o car.o neighbor.o -lm

main.o: main.c neighbor.h main.h car.h
	$(CC) $(CFLAGS) -c main.c

car.o: car.c car.h
	$(CC) $(CFLAGS) -c car.c

neighbor.o: neighbor.c car.h neighbor.h
	$(CC) $(CFLAGS) -c neighbor.c

clean:
	$(RM) cars *.o 
