CC := gcc
CFLAGS := -Isrc -std=c99 -Wall -Wextra

FORMAT := clang-format
FORMATFLAGS := -i

SRC := $(wildcard src/*.c src/*/*.c)
HEADERS = $(wildcard src/*.h src/*/*.h)
OBJ := $(SRC:.c=.o)
BIN := starlark

default: all

$(BIN): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all
all: $(BIN)

.PHONY: clean
clean:
	rm -f $(OBJ) $(BIN)

.PHONY: format
format:
	$(FORMAT) $(FORMATFLAGS) $(SRC) $(HEADERS)
