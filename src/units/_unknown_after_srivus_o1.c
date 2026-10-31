/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

extern int D_004A6F60;
// MATCH func_001899D8
int FUN_001899d8(int a) { D_004A6F60 = D_004A6F60 + 1; __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return a; }

