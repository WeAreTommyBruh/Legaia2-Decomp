/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int w0, w4; int *w8; } S_0024CF68;
extern char D_0045E028[]; void func_001118F8_0024CF68(char *) __asm__("func_001118F8");
// MATCH func_0024CF68
int FUN_0024cf68(S_0024CF68 *s) { if (s->w4 <= 0) func_001118F8_0024CF68(D_0045E028); s->w4--; return s->w8[s->w4]; }

typedef struct { int w0; int w4; int *w8; } O_0024CEE8;
extern char D_0045E018[]; void func_001118F8_0024CEE8(char *) __asm__("func_001118F8");
// MATCH func_0024CEE8
int FUN_0024cee8(O_0024CEE8 *o, int v) { if (o->w4 < 0) func_001118F8_0024CEE8(D_0045E018); if (o->w4 >= o->w0) func_001118F8_0024CEE8(D_0045E018); return o->w8[o->w4++] = v, o->w4 - 1; }

extern int D_003FEBB4[];
extern char D_003E9DF0[];
// MATCH func_0025A508
int FUN_0025a508(void)
{
    int buf[68];
    int i; unsigned k; int n;
    char *p, *q;
    for (i = 0; i < 64; i++) {
        if ((D_003FEBB4[i / 32] >> i) & 1) buf[i] = 0;
        else buf[i] = 1;
    }
    n = 0;
    q = D_003E9DF0;
    p = q + 8;
    for (k = 0; k < 60; k++) {
        int idx = *(int *)p;
        if (buf[idx] == 0) {
            buf[idx] = 1;
            n++;
        }
        p += 168;
    }
    return n;
}
extern int D_004A1A20_24E158 __asm__("D_004A1A20");
float func_0021AF68_24E158(int) __asm__("func_0021AF68");
// MATCH func_0024E158
float FUN_0024e158(int a, int b) { float x, y; x = func_0021AF68_24E158(D_004A1A20_24E158 + a * 0x1560); if (*(int *)(*(int *)(a * 0x1560 + D_004A1A20_24E158 + 0x1444) + 0x38) == 0 && x < 2.0f) x = x * 1.5f; y = func_0021AF68_24E158(D_004A1A20_24E158 + b * 0x1560); if (*(int *)(*(int *)(b * 0x1560 + D_004A1A20_24E158 + 0x1444) + 0x38) == 0 && y < 2.0f) y = y * 1.5f; return (x + y) * 5120.0f; }

