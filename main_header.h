#ifndef MAIN_HEADER

#define MAIN_HEADER
#pragma warning (disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#include "func_header.h"

#define row 10
#define col 10

typedef struct cord {
	int x[6];
	int y[6];
	char direct[6];
}cord;

#endif

