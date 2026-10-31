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
