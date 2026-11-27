#include "../common.h"
typedef struct { char p[6372]; signed char t[5]; } T;
extern T D_003FEBA8;
typedef struct { char p[104]; signed char c; } C;
typedef struct { char p[12]; int v; char q[136 - 16]; int a[8]; } O;
C *func_0024F380(int);
O *func_0025A7D0(void);
// MATCH func_001A0A58
int FUN_001a0a58(void) { int i = 0; int v; int *p; O *o = func_0025A7D0(); if (o->a[0] != 0) { p = o->a; do { C *c = func_0024F380(*p); if (c->c <= 0) return 0; i++; p++; } while (i < 8 && *p != 0); } v = o->v - 1; for (i = 0; i < 5; i++) if (D_003FEBA8.t[i] == v) return 1; return 0; }
