/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[32]; char b32; } O_00202C30;
extern int D_004A3864; extern char D_00454260[]; int func_00196FF8(void); void func_001118F8_00202C30(char *, int) __asm__("func_001118F8"); void func_00202F88(O_00202C30 *);
// MATCH func_00202C30
int eftpack_00202c30(O_00202C30 *o) { if (o->b32 == 0) { int r = func_00196FF8(); o->b32 = 1 - r; if (D_004A3864 & 0x400) func_001118F8_00202C30(D_00454260, o->b32); if (o->b32 != 0) func_00202F88(o); } return o->b32; }
