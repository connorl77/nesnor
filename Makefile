CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinclude
SRC     = src/main.c src/mem.c src/cpu.c src/cpu_ops.c
OBJ     = $(SRC:.c=.o)
TARGET  = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

