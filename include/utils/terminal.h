#pragma once

#include <utils/arguments.h>
#include <locale.h>

#define CLEAR_SCREEN() printf("\x1b[J")
#define ANSI(c) (get_arguments().no_ansi ? "" : (c))

#define RGB(r,g,b) "\x1b[38;2;" #r ";" #g ";" #b "m"
#define RGB_BG(r,g,b) "\x1b[48;2;" #r ";" #g ";" #b "m"

#define RESET       RGB(255, 255, 255)
#define RESET_BG    RGB_BG(0,0,0)

#define LOG_INFO    "\x1b[38;2;0;200;255m[INFO]" RESET "  "
#define LOG_OK      "\x1b[38;2;0;255;0m[OK]" RESET "    "
#define LOG_WARN    "\x1b[38;2;255;180;0m[WARN]" RESET "  "
#define LOG_ERROR   "\x1b[38;2;255;50;50m[ERROR]" RESET " "

#define RED          "\x1b[38;2;255;0;0m"
#define GREEN        "\x1b[38;2;0;255;0m"
#define BLUE         "\x1b[38;2;0;0;255m"
#define YELLOW       "\x1b[38;2;255;255;0m"
#define MAGENTA      "\x1b[38;2;255;0;255m"
#define CYAN         "\x1b[38;2;0;255;255m"
#define WHITE        "\x1b[38;2;255;255;255m"
#define BLACK        "\x1b[38;2;0;0;0m"
#define ORANGE       "\x1b[38;2;255;165;0m"
#define PURPLE       "\x1b[38;2;128;0;128m"
#define PINK         "\x1b[38;2;255;192;203m"
#define GRAY         "\x1b[38;2;128;128;128m"
#define LIGHT_GRAY   "\x1b[38;2;192;192;192m"