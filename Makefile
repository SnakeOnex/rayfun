# Compiler to use
CC = gcc

# Compiler flags (Wall enables warnings, g enables debugging)
CFLAGS = -Wall -g

# Linker flags
LDFLAGS = libraylib.a -lGL -lm -lpthread -dl -lrt -lX11

# Target executable name
TARGET = pendulum

# Source file
SOURCE = main.c

# Object files (intermediate compiled files)
OBJECT = main.o

# Default target: build the executable
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECT)
	$(CC) -o $(TARGET) $(OBJECT) $(LDFLAGS)

# Compile the source file
$(OBJECT): $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE)

clean:
	rm -f $(TARGET) $(OBJECT)
