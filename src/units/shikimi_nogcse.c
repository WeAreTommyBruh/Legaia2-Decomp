// cflags: -fno-gcse
/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p0[0x18]; unsigned f18; char p1c[0xc0 - 0x1c]; unsigned fc0; char pc4[0x178 - 0xc4]; short f178, f17a; } Ef32a8_002B32A8;
extern int D_004A6AA0_2B32A8 __asm__("D_004A6AA0");
void func_00130C58_2B32A8(float, int, int, int, int) __asm__("func_00130C58");
// MATCH func_002B32A8
void shikimi_002b32a8(Ef32a8_002B32A8 *e) { float fr = 1.0f; int id, x, y; short a = e->f17a; unsigned short n; if (a != e->f178) fr = (fr / (float)a) * (float)(a - e->f178); else fr = 0.0f; switch (e->fc0) { case 0x1000: id = 0xf9; x = 0x90; y = 0x10; break; case 0x4000: id = 0xfb; x = 0x90; y = 0xd0; break; case 0x8000: id = 0xfc; x = 0x10; y = 0x68; break; case 0x2000: id = 0xfa; x = 0x10; __asm__ volatile ("" : : "r"(id)); y = 0x68; break; case 0x10: fr = 1.0f; id = 0x95; x = 0xc8; y = 0x20; break; case 0x40: fr = 1.0f; id = 0x97; x = 0xc8; y = 0x60; break; case 0x80: fr = 1.0f; id = 0x94; x = 0xa8; y = 0x40; break; case 0x20: id = 0x96; fr = 1.0f; x = 0xe8; y = 0x40; break; case 0x4: id = 0x142; x = 0xe8; y = 0x40; fr = 1.0f; break; case 8: goto do8; default: goto skip; } func_00130C58_2B32A8(fr, id, x, y, 0x80); goto skip; do8: func_00130C58_2B32A8(1.0f, 0x143, 0xe8, 0x40, 0x80); skip: n = e->f178; e->f178 = n + 1; if (e->f17a != -1 && e->f17a <= (short)(n + 1)) e->f18 |= 8; if (D_004A6AA0_2B32A8 != 0) { D_004A6AA0_2B32A8 = 0; e->f18 |= 8; } }
