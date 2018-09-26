CC=gcc
CFLAGS= -Wall -std=c99 -g

all: q1.c q2.c q3.c q7.c clean
	$(CC) -o all q1.c q2.c q3.c q7.c 

q1: q1.c
	$(CC) -o q1 q1.c

q2: q2.c
	$(CC) -o q2 q2.c

q3: q3.c
	$(CC) -o q3 q3.c

q7: q7.c
	$(CC) -o q7 q7.c

shell: shell.c
	$(CC) -o shell shell.c

clean: rm -f *.o
