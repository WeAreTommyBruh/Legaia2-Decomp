// cflags: -fno-gcse
#include "../common.h"
typedef struct { short s0; short s2; short s4; short s6; char name[32]; char pad[2]; char c42; char rest[37]; } T_0021AAF8;
extern T_0021AAF8 D_003210E0[];
typedef struct { char p0[0x12e0]; int c; int pad; char name[32]; char p1[0x1364-0x1308]; int idx; char p2[0x1448-0x1368]; int b; char p3[12]; int a; } O_0021AAF8;
int func_0021AE30(void *, int);
// MATCH func_0021AAF8
void FUN_0021aaf8(O_0021AAF8 *o) { int i; if (func_0021AE30(o, o->idx) != 0) { T_0021AAF8 *t = &D_003210E0[o->idx]; t->s4 = o->a; t->s0 = o->b; t->c42 = o->c; for (i = 0; i < 32; i++) D_003210E0[o->idx].name[i] = o->name[i]; } }
