CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs
FP = -fPIC

all: StrList

StrList: StrList.o Main.o
	$(CC) $(CFLAGS) -o $@ $^

StrList.o: StrList.c StrList.h
	$(CC) $(CFLAGS) -c $<

Main.o: Main.c StrList.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o StrList
