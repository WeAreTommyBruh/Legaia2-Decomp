/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { char p0[4]; int w4, w8, w12, w16, w20, w24, w28; char b32, b33; } O_00202BC8;
extern int D_004A3864, D_004A384C; extern char D_00454238[]; void func_001118F8(char *);
// MATCH func_00202BC8
void eftpack_00202bc8(O_00202BC8 *o) { if (D_004A3864 & 0x400) func_001118F8(D_00454238); o->b33 = 0; o->b32 = 1; o->w28 = 0; o->w4 = 0; o->w8 = 0; o->w12 = 0; o->w16 = 0; o->w20 = 0; o->w24 = 0; D_004A384C = 0; }
