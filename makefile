S_FILES = main.c queue.c print.c
O_FILES = main.o

all:
	gcc -Wall ${S_FILES} -o main.o

open:
	main:
		code main.c
	queue:
		code queue.c queue.h
	print:
		code print.c print.h

rm:
	rm O_FILES