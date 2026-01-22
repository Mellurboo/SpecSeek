#pragma once
#include <stdint.h>
#include <syscalls/ioctl.h>

#define FB_GET_INFO     0x1001
#define FB_DRAW_PIXELS  0x1003
#define FB_FILL_RECT    0x1004

typedef struct {
    uint32_t x, y;
    uint32_t width, height;
    uint32_t pitch;
    uint8_t  bpp;
    uint8_t *pixels;
} fb_pixel_buffer_t;

typedef struct fb_square {
    uint32_t x, y;
    uint32_t width, height;
    uint32_t color;
} fb_square_t;

typedef struct {
    uint64_t addr;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    uint32_t bpp;
} fb_info_t;

int fb_draw_pixels(int fd, fb_pixel_buffer_t *buf) {
    return _ioctl(fd, FB_DRAW_PIXELS, buf);
}

int fb_fill_rect(int fd, uint32_t x, uint32_t y, uint32_t w, uint32_t h, uint32_t color) {
    struct fb_square s = {x, y, w, h, color};
    return _ioctl(fd, FB_FILL_RECT, &s);
}
