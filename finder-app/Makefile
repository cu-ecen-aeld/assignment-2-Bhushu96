# Makefile for finder-app/writer

# Detect CROSS_COMPILE prefix; default to empty (native build)
CROSS_COMPILE ?= 

# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra -O2

# Source and target
SRC := writer.c
TARGET := writer

# Default target: build the application
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# Clean target: remove binary and object files
clean:
	rm -f $(TARGET) *.o

# Phony targets
.PHONY: all clean
