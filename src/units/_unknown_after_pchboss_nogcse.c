/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { char p[4832]; int w4832; char p2[316]; char b5152[32]; } O_0021B018;
// MATCH func_0021B018
void FUN_0021b018(O_0021B018 *o) { int i; for (i = 0; i < o->w4832; i++) o->b5152[i] = 1; for (i = o->w4832; i < 32; i++) o->b5152[i] = 0; }

typedef struct { short s0; short s2; short s4; short s6; char name[32]; char pad[2]; char c42; char rest[37]; } T_0021AA60;
extern T_0021AA60 D_003210E0_21AA60[] __asm__("D_003210E0");
typedef struct { char p0[0x12e0]; int c; int pad; char name[32]; char p1[0x1364-0x1308]; int idx; char p2[0x1448-0x1368]; int b; char p3[12]; int a; } O_0021AA60;
int func_0021AE30_21AA60(void *, int) __asm__("func_0021AE30");
// MATCH func_0021AA60
void FUN_0021aa60(O_0021AA60 *o) { int i; if (func_0021AE30_21AA60(o, o->idx) != 0) { T_0021AA60 *t = &D_003210E0_21AA60[o->idx]; o->a = t->s4; o->b = t->s0; o->c = t->c42; for (i = 0; i < 32; i++) o->name[i] = D_003210E0_21AA60[o->idx].name[i]; } }

