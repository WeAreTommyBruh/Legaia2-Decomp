/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[40]; int w40, w44; char p2[4]; int w52, w56, w60; } E_00186AC0;
typedef struct { E_00186AC0 e[64]; int w4096; float f4100, f4104; int w4108, w4112, w4116, w4120, w4124, w4128, w4132; } O_00186AC0;
// MATCH func_00186AC0
void FUN_00186ac0(O_00186AC0 *o) { int i; E_00186AC0 *e; o->w4108 = 0; o->f4100 = 32.0f; o->f4104 = 32.0f; o->w4112 = 0; o->w4116 = 0; o->w4120 = 0; o->w4124 = 0; o->w4128 = 0; o->w4132 = 0; o->w4096 = 0; e = o->e; for (i = 63; i >= 0; i--) { e->w40 = 0; e->w52 = 0; e->w44 = 0; e->w56 = 0; e->w60 = 0; e++; } }

extern char D_0043FED0[], D_0043FE88[];
int func_00202840(void *);
// MATCH func_00186EC8
void *FUN_00186ec8(void *s) {  (*(int *)((char *)s + 2116)) = (int)D_0043FED0; func_00202840((char *)s + 24); (*(int *)((char *)s + 2128)) = -1; (*(int *)((char *)s + 2116)) = (int)D_0043FE88; (*(int *)((char *)s + 2132)) = -1; (*(int *)((char *)s + 2136)) = 0; (*(int *)((char *)s + 2140)) = 0; (*(int *)((char *)s + 2144)) = 0; (*(int *)((char *)s + 2148)) = 0; return s; }
