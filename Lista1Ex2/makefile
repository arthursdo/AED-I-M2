CC = gcc
CFLAGS = -W -Wall -std=c99 -g
bb = biblioteca


all:full

agenda: $(bb).o
	$(CC) $(CFLAGS) main.c $(bb).o -o agenda.exe

main.o: main.c
	$(CC) $(CFLAGS) main.c -o main.o
	
$(bb).o: $(bb).c $(bb).h
	$(CC) $(CFLAGS) $(bb).c $(bb).h -o $(bb).o

full: main.c
	$(CC) $(CFLAGS) main.c $(bb).c $(bb).h -o agenda.exe