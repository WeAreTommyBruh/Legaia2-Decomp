/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_0025E4D8;
typedef struct { int w0, w4, w8, w12, w16; char p[16]; V8_0025E4D8 v; } O_0025E4D8;
extern V8_0025E4D8 D_004A59B0[];
// MATCH func_0025E4D8
void FUN_0025e4d8(O_0025E4D8 *o, int x) { o->w8 = x; o->w16 = 0; o->v = D_004A59B0[0]; }

typedef struct { char p[54]; short s54; char q[16]; } E72_0024F028;
extern E72_0024F028 D_003FDFA0_24F028[] __asm__("D_003FDFA0");
// MATCH func_0024F028
int FUN_0024f028(int i) { E72_0024F028 *e; if ((unsigned)i < 5) { e = &D_003FDFA0_24F028[i]; return e->s54 / 18; } return 0; }

