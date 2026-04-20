CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = s21_cat
SOURCES = main.c parser.c printer.c file.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = s21_cat.h

.PHONY: all format clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

format:
	clang-format -i $(SOURCES) $(HEADERS)

clean:
	rm -f $(OBJECTS) $(TARGET)