/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"


// MATCH func_001F4900
int misuzu_001f4900(char *s) { int r = 0, sign = 1; char *p; char *q; unsigned char c; int t; if (*s != 0) { p = s; q = p; do { if (p == q && *s == 45) { sign = -1; } else { c = *p; if ((unsigned)(c - 42) >= 16) break; t = r * 10 - 48; r = t + (char)c; p++; } } while (*p != 0); } return r * sign; }

