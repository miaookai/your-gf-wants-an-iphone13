CC=gcc
CFLAGS=-O -Wall

all:iphone13

sl: sl.c sl.h
	$(CC) $(CFLAGS) -o sl sl.c -lncurses

iphone13: iphone13.c iphone13.h
	$(CC) $(CFLAGS) -o iphone13 iphone13.c -lncurses

clean:
	rm -f iphone13

distclean: clean
