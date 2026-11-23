/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern float D_004A70B8_231130 __asm__("D_004A70B8");
extern int D_004A14C4_231130 __asm__("D_004A14C4");
void func_0021B998_231130(float, void *, unsigned short *, int, int, int) __asm__("func_0021B998");
void func_002306E8_231130(void *, int, unsigned short *, int) __asm__("func_002306E8");
void func_00239568_231130(void *) __asm__("func_00239568"); extern char D_0045C140_231130[] __asm__("D_0045C140");
typedef struct { char p0[0x18]; int flags; char p1c[8]; float f24; char p28[0x30]; float f58; char p5c[0x34]; int (*tab)[0x300]; } O_00231130;
// MATCH func_00231130
void FUN_00231130(O_00231130 *p, int i, unsigned short *k, int d) { int h = *(int *)((char *)p->tab + (i << 2) + 0x918); int f = 0; if (h != 0) f = *(int *)(h + 0x70) & 0x10; if ((p->f58 > D_004A70B8_231130 && h == 0 && f != 0) || !(p->flags & 0x10000000)) { func_002306E8_231130(p, i, k, d); } else if (*k & 0x800) { func_0021B998_231130(p->f24, p, k, i, 0, *(int *)((char *)p->tab + (i << 2) + 0x918)); } else if (D_004A14C4_231130 != 0) { func_00239568_231130(D_0045C140_231130); } }
