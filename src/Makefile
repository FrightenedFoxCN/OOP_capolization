CC = g++
INC = utils\include ..\include ../lib
CFLAGS = -I${INC}, -ggdb, -Wall, -Wextra, -O0
SRC = main.cpp core/character.cpp core/dialog.cpp
OBJS = main.o core/character.o core/dialog.o


main: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o test.exe

.c.o:
	${CC} -Ilib ${CFLAGS} $< -c
