all: main
main: main.o llist.o queue.o stack.o
	gcc main.o llist.o queue.o stack.o -o main
main.o:main.c llist.h stack.h queue.h
	gcc -c main.c llist.h stack.h queue.h
llist.o:llist.c llist.h stack.h queue.h
	gcc -c llist.c llist.h
stack.o:stack.c llist.h stack.h queue.h
	gcc -c stack.c stack.h
queue.o: queue.c llist.h stack.h queue.h
	gcc -c queue.c queue.h

run:
	./main