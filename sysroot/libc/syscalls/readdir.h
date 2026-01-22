#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct dirent {
    char name[256];
    int type;
} dirent_t;

long _readdir(int fd, size_t index, dirent_t *out);