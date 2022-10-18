S_FILES = main.c queue.c print.c
O_FILES = main.o

all:
	gcc -Wall ${S_FILES} -o executable.o

open_main:
	code main.c
open_queue:
	code queue.c queue.h
open_print:
	code print.c print.h

rm:
	rm ${O_FILES}