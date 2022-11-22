S_FILES = main.c string.c priority_queue.c map.c linked_list.c
O_FILES = a.o

all:
	gcc -Wall ${S_FILES} -o a.o

open_main:
	code main.c

open_print:
	code print.c print.h

rm:
	rm ${O_FILES}