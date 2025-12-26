CC      = gcc
CFLAGS  = -Iinclude -g -DCPU_TEST_MODE
SRC     = src/main.c src/mem.c src/cpu.c src/bus.c src/cartridge.c
OBJ     = $(SRC:.c=.o)
TARGET  = program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

