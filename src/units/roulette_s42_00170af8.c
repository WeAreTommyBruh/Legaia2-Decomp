// cflags: -fno-gcse
#include "../ghidra.h"
// MATCH func_00170AF8
void roulette_00170af8(int *p) { int n = p[20]; p[18] = (p[18] & 0xffff0000) + 0x10000; { int v; if (p[18] >= n << 16) { v = p[18]; L: v -= n << 16; if (v >= n << 16) goto L; p[18] = v; } } p[19] = 0; }
