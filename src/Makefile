# Makefile in src to generate object files only

CC = gcc
SRC_DIR = .
OBJ_DIR = ../obj

SRC_FILES = $(wildcard *.c)
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $< -o $@

.PHONY: all clean

all: $(OBJ_FILES)

clean:
	rm -f $(OBJ_DIR)/*.o
