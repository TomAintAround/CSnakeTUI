CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS =
SRCDIR = src
BUILD_DIR = build
SRC = $(wildcard $(SRCDIR)/*.c)
EXEC = $(patsubst $(SRCDIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
TARGET = $(BUILD_DIR)/CSnakeTUI

LDFLAGS += -lncursesw -lm

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(EXEC)
	$(CC) $(EXEC) $(LDFLAGS) -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
