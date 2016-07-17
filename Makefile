CC = gcc
ifeq ($(origin CC_ARM), undefined)
CC_ARM = arm-linux-gnueabi-gcc
endif
CFLAGS = -Wall -g

favlist: favlist.c
	${CC} ${CFLAGS} -o favlist favlist.c

arm: favlist.c
	${CC_ARM} ${CFLAGS} -static -o favlist_arm favlist.c

all: favlist arm

clean:
	rm -f favlist favlist_arm
