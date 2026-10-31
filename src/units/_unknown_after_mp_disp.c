/* Functions of this report unit, matched by hand. */
#include "../common.h"

int func_002CCCA8(int, int, int, int *); int func_002E9F90(int);
// MATCH func_00195430
int FUN_00195430(int *o, int a, int b) { int buf[4]; if (o[0] != 0) return func_002CCCA8(b >> 11, a, 1, buf) << 11; return func_002E9F90(o[12]); }

extern int D_004A3798; extern char D_00321300_00195210[] __asm__("D_00321300");
void func_00194A48(int);
// MATCH func_00195210
int FUN_00195210(void) { if (D_004A3798 != 0) { func_00194A48((int)D_00321300_00195210); D_004A3798 = 0; } __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); return 0; }

int func_002E9950(char *, int); int func_002E9D58(int, int, int); int func_002E9BD8_001954B0(int) __asm__("func_002E9BD8");
// MATCH func_001954B0
int FUN_001954b0(char *name, int *out) { int h; int r; h = func_002E9950(name, 1); if (h < 0) return h; r = func_002E9D58(h, 0, 2); *out = r; if (r < 0 || func_002E9D58(h, 0, 0) < 0) { func_002E9BD8_001954B0(h); return -1; } return h; }
