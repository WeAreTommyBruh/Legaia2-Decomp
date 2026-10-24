#include "../src/common.h"
// 3 words differ
// WIP func_002E7000
int FUN_002e7000(int c) { while (*(volatile unsigned *)0x1000f130 & 0x8000); *(volatile unsigned char *)0x1000f180 = c; return c; }
