/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char p0[4]; char *w4; char p8[12]; unsigned short *w20; char p24[28]; unsigned short h52; char p54[4]; unsigned short h58; } O_00242470;
extern int D_004A1270_242470 __asm__("D_004A1270");
void func_00242598_242470(void *, void *, int) __asm__("func_00242598");
// MATCH func_00242470
int FUN_00242470(O_00242470 *o, int c) { char *b; unsigned short *p; int i; D_004A1270_242470 = 10; if (o->h52 == 0 || o->w20 == 0) return -1; b = o->w4; c &= 0xffffff; if (o->h58 > 1000) o->h58 = 1000; if (*(volatile int *)&D_004A1270_242470 < 9) { for (i = 1; i < o->h58; i++) ; } else { D_004A1270_242470 = 1; i = 1; if (i < o->h58) { p = o->w20 + 2; do { func_00242598_242470(b + p[0] * 16, b + p[1] * 16, c); p += 2; i++; } while (i < o->h58); } D_004A1270_242470 = 10; } return 0; }
