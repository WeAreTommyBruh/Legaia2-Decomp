/* Small functions matched by hand. */
// cflags: -fno-schedule-insns -fno-schedule-insns2
#include "common.h"

typedef struct { int a0, a4, a8, a12, a16, a20; } N_2da070_002DA070;
extern N_2da070_002DA070 *D_00631AF8[];
// MATCH func_002DA070
void FUN_002da070(int a, N_2da070_002DA070 *s) { N_2da070_002DA070 *h = D_00631AF8[0]; s->a12 = a; s->a20 = (int)h; D_00631AF8[0] = s; s->a8 = a; s->a4 = 0; s->a0 = 0; s->a16 = 0; }

extern int D_004A6F54; void func_0018A658(char *, char *); char *func_002DD1DC(char *, int); int *func_0018A708(char *);
// MATCH func_0018B250
int FUN_0018b250(char *name) { char buf[256]; char *p; int *e; int w; func_0018A658(name, buf); p = func_002DD1DC(buf, 58); if (p == 0) p = buf; else p++; e = func_0018A708(p); if (e == 0) return -1; w = e[3]; return D_004A6F54 + w; }
