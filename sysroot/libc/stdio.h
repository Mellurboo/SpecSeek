#pragma once
#include <stddef.h>
#include <stdarg.h>
#include <stdint.h>

#define stdin   0
#define stdout  1
#define stderr  2

int printf(const char *fmt, ...);
int fprintf(int fd, const char *fmt, ...);
int vfprintf(int fd, const char *fmt, va_list ap);
int vsnprintf(char *buf, size_t size, const char *fmt, va_list ap);
int snprintf(char *buf, size_t size, const char *fmt, ...);