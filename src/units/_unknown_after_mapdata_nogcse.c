/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[40]; short h40, h42; char q[4]; } E_0015DE00;
typedef struct { char p[28]; E_0015DE00 *w28; int w32; } O_0015DE00;
int func_0015DAC8(E_0015DE00 *, int);
// MATCH func_0015DE00
E_0015DE00 *FUN_0015de00(O_0015DE00 *o, int k, int x) { int i; E_0015DE00 *e = o->w28; for (i = 0; i < o->w32; i++, e++) { if (e->h40 == k && func_0015DAC8(e, x) != 0) return e; } return 0; }

typedef struct { char p[16]; char q[24]; short h40, h42; char r[4]; } E_0015DBA8;
typedef struct { char p[28]; E_0015DBA8 *w28; int w32; } O_0015DBA8;
int func_0015DAC8_0015DBA8(E_0015DBA8 *, int) __asm__("func_0015DAC8");
// MATCH func_0015DBA8
char *FUN_0015dba8(O_0015DBA8 *o, int k, int x) { int i; int best = -1; char *res = 0; E_0015DBA8 *e = o->w28; for (i = 0; i < o->w32; i++, e++) { if (e->h40 == k && func_0015DAC8_0015DBA8(e, x) != 0 && e->h42 >= best) { best = e->h42; res = e->p + 16; } } return res; }

int func_0015C398(int, void *, float);
// MATCH func_0015C7F0
int FUN_0015c7f0(int *o, float *q, float r, float s) { float v[4]; int i; int *p; v[0] = q[0]; v[1] = q[1] - s; v[2] = q[2]; v[3] = q[3]; if (func_0015C398(o[0], v, r)) return 1; p = (int *)o[3]; for (i = 0; i < o[4]; i++, p++) { char *e = (char *)*p; if (*(short *)(e + 284) != 0 && *(short *)(e + 286) != 0) if (func_0015C398((int)e, v, r)) return 1; } return 0; }

int func_0015CFB0(int, int);
// MATCH func_0015D530
int FUN_0015d530(int *o, int a) { int i; int **p; func_0015CFB0(o[0], a); p = (int **)o[3]; for (i = 0; i < o[4]; i++) { char *e = (char *)*p; if (*(short *)(e + 284) != 0) if (*(short *)(e + 286) != 0) func_0015CFB0((int)e, a); p++; } return 0; }
