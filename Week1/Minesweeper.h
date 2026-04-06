#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// Linux 환경을 위한 헤더 (conio.h 대체)
#include <termios.h>
#include <unistd.h>

extern void playMineSweeper(int nBomb);
