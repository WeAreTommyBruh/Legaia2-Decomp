/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { int a0, a4, a8; } E_0021EAB0;
typedef struct { char pad[7240]; E_0021EAB0 e[32]; int n; } S_0021EAB0;
void func_0021EB20(void *, int, int, int);
// MATCH func_0021EAB0
void batread_0021eab0(S_0021EAB0 *s) { int i; for (i = 0; i < s->n; i++) func_0021EB20(s, s->e[i].a4, s->e[i].a8, s->e[i].a0); }

extern unsigned D_004A6FC4;
// MATCH func_0021EFE0
void batread_0021efe0(char *o) { int i; int *q; char *p; *(int *)(o + 0x1bf0) = 0; *(int *)(o + 0x1bec) = 0; *(int *)(o + 0x1bf4) = 0; q = (int *)(o + 0x1ba8); for (i = 15; i >= 0; i--) { *q = 0; q--; } p = o + 0x1200; do { if (*p == 8) *p = 0; p++; } while ((int)p < (int)(o + 0x1240)); D_004A6FC4 = 0; }

