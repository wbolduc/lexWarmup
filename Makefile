#
# Makefile for TINY scanner using flex
#

CC = gcc

CFLAGS = 

OBJS = lex.yy.o util.o main.o stringStack.o

scanner: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o scanner -ll

main.o: main.c globals.h util.h scan.h
	$(CC) $(CFLAGS) -c main.c

stringStack.o: stringStack.c stringStack.h
	$(CC) $(CFLAGS) -c stringStack.c

util.o: util.c util.h globals.h
	$(CC) $(CFLAGS) -c util.c

lex.yy.c: SGML.l
	flex SGML.l

lex.yy.o: lex.yy.c globals.h util.h
	$(CC) $(CFLAGS) -c lex.yy.c

clean:
	rm -f scanner $(OBJS) lex.yy.c
