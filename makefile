TARGET      = specseek
CC         := gcc
BIN_DIR     = bin
OBJ_DIR     = $(BIN_DIR)/obj

VENDOR_DIR  = ../libspecseek/bin/elf/

C_FLAGS     = -Wall -Wextra -Werror -Wno-unused-parameter -m64 \
              -Iinclude \
              -I$(VENDOR_DIR)

LD_FLAGS    = -m64 -L$(VENDOR_DIR) -lspecseek

SRCS        = $(shell find src -name '*.c')
OBJS        = $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) $(LD_FLAGS) -o $(BIN_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) -c $< -o $@

build: $(TARGET)

run: $(TARGET)
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf bin

.PHONY: all build clean