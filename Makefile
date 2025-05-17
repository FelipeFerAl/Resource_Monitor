#Top-level Makefile

CC = gcc
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = test
TEST_SRC_DIR = $(TEST_DIR)/src

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
SRC_NAMES = $(notdir $(basename $(SRC_FILES)))

TEST_NAMES = cpuinfo_test meminfo_test tui_test
TEST_SRCS = $(patsubst %, $(TEST_SRC_DIR)/%.c, $(TEST_NAMES))
TEST_BINS = $(patsubst %, $(BIN_DIR)/%, $(TEST_NAMES))

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_NAMES)))
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@

# Ensure folders exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

.PHONY: all resource_mon tests clean

all: resource_mon tests

resource_mon: $(OBJ_FILES)
	$(CC) -o $(BIN_DIR)/resource_mon $^

tests: $(TEST_BINS)

$(BIN_DIR)/%: $(TEST_SRC_DIR)/%.c $(filter-out $(OBJ_DIR)/resource_mon.o, $(OBJ_FILES))
	$(CC) $^ -o $@

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*
