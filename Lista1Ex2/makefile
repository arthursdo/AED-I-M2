CC = gcc
CFLAGS = -W -Wall -std=c99 -g
bb = biblioteca
ag = agenda


all:$(ag)

$(ag): main.c $(bb).c $(bb).h
	$(CC) $(CFLAGS) main.c $(bb).c $(bb).h -o $(ag).exe

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o
	
$(bb).o: $(bb).c $(bb).h
	$(CC) $(CFLAGS) $(bb).c $(bb).h -o $(bb).o

full.o: main.c
	$(CC) $(CFLAGS) main.c $(bb).c $(bb).h -o $(ag).out