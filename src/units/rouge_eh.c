/* Functions of this report unit, matched by hand. */
// cflags: -fexceptions
#include "../common.h"

extern int D_004A3864; extern char D_00432A98[], D_004327B0[]; void func_001118F8(char *, ...); void func_00162130(char *, char *, int);
// MATCH func_001334D0
void rouge_001334d0(char *o, int a, int b) { if (b != 1322 && (D_004A3864 & 0x40)) func_001118F8(D_00432A98, a, b, o); func_00162130(o, D_004327B0, 786); }
