/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct { char b0; char p[23]; int w24; } E_0025D0F0;
extern E_0025D0F0 D_003E2010[]; extern char D_0047B0E0[];
// MATCH func_0025D0F0
int FUN_0025d0f0(int a) { E_0025D0F0 *p = D_003E2010; E_0025D0F0 *e = p + 253; do { if (p->b0 == a) return p->w24; p++; } while (p < e); return (int)D_0047B0E0; }

extern unsigned short D_004A5990, D_004A5992; void func_002552B8(void);
// MATCH func_00255278
void FUN_00255278(unsigned a) { if (a < 9) { if (a == 7) D_004A5992 = D_004A5990; if (a == 8) D_004A5990 = D_004A5992; else D_004A5990 = a; func_002552B8(); } }
