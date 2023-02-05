.PHONY: all clean

CC=gcc
CFLAGS=-std=c99
LIBS=-lraylib -lm -lpthread -ldl
MAKE=make
PROJECT_NAME=mikesrpg
ODIR=obj

SOURCE_FILES ?= \
	worldmap.c \
	drawimage.c \
	npc.c \
	main.c

OBJS = $(patsubst %.c, %.o, $(SOURCE_FILES))

all: 
	$(MAKE) $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJS)
	$(CC) -o $(PROJECT_NAME) $(OBJS) $(CFLAGS) $(LIBS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(LIBS)

clean:
	find . -type f -executable -delete
	rm -fv *.o