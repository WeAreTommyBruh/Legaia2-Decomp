#include "../common.h"
typedef struct { int a; int b; } T_215890;
typedef struct { int w0; T_215890 *t; int x; char p[16]; int s; char q[4]; int f; } O_215890;
extern unsigned long D_004A12D8; extern char D_00343028[]; extern T_215890 D_003C2E40[];
int rsound_0010c2b0(char *, int, int, int, int, int, int);
// MATCH func_00215890
int FUN_00215890(O_215890 *o) { int s = 100; unsigned long m = D_004A12D8 & 0x200840; if (o->f == 0) s = 0; o->s = s; if (m != 0 && s >= 100 && o->x + 120 < o->t->b) { rsound_0010c2b0(D_00343028, 0, 2, 0, 1, 0, 0); o->s = 102; o->t = D_003C2E40; o->x = D_003C2E40[0].b + 60; } return 1; }
