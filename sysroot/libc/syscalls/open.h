#pragma once

#define O_RDONLY  0x1
#define O_WRONLY  0x2
#define O_RDWR    (O_RDONLY | O_WRONLY)
#define O_CREAT   0x4
#define O_TRUNC   0x8
#define O_APPEND  0x10

int _open(const char *path, int flags);