
ELF_TARGET_64 = specseek


CC ?= x86_64-elf-gcc

ELF_BIN_DIR_64 = bin
ELF_OBJ_DIR_64 = $(ELF_BIN_DIR_64)/obj

LIB_DIR = sysroot/lib
LIBC = $(LIB_DIR)/blibc.a
CRT0 = $(LIB_DIR)/start.o


COMMON_CFLAGS = \
	-ffreestanding \
	-fno-stack-protector \
	-fno-stack-check \
	-Wall -Wextra \
	-nostdlib \
	-no-pie \
	-m64 \
	-Iinclude \
	-Isysroot/libc

LDFLAGS = \
	-static \
	-nostdlib \
	-no-pie \
	-m64 \
	-Iinclude \
	-L$(LIB_DIR) \
	-Isysroot/libc

SRCS = $(shell find src -name '*.c')
ELF_OBJS_64 = $(patsubst src/%.c,$(ELF_OBJ_DIR_64)/%.o,$(SRCS))

all: $(ELF_TARGET_64)

$(ELF_TARGET_64): $(CRT0) $(ELF_OBJS_64)
	@mkdir -p $(ELF_BIN_DIR_64)
	$(CC) $(LDFLAGS) \
		-o $(ELF_BIN_DIR_64)/$(ELF_TARGET_64) \
		$(CRT0) \
		$(ELF_OBJS_64) \
		-l:blibc.a

$(ELF_OBJ_DIR_64)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(COMMON_CFLAGS) -c $< -o $@

build: $(ELF_TARGET_64)

clean:
	rm -rf bin

.PHONY: all clean
