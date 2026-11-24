/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "../common.h"

// compiler: 990721-r5900
// cflags:
// MATCH func_00211BD8
int FUN_00211bd8(signed char *a, signed char *ae, signed char *b, signed char *be) { for (; a != ae && b != be; a++, b++) { if (*a < *b) return -1; if (*b < *a) return 1; } return b != be ? -1 : a != ae; }

