CC = gcc
CFLAGS = -Wall -g

favlist: favlist.c
	${CC} ${CFLAGS} -o favlist favlist.c

clean:
	rm -f favlist
