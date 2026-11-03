/* Functions of this report unit, matched by hand. */
// cflags: -O1
#include "../common.h"

typedef struct { char p[16]; int w16; char q[4]; int w24; } S_002E8B18;
typedef struct { S_002E8B18 *s; int k; } P_002E8B18;
// MATCH func_002E8B18
int FUN_002e8b18(P_002E8B18 *p) { S_002E8B18 *q = p->s; if (q == 0 || p->k != q->w24 || (q->w16 & 1) == 0) return 0; return 1; }

typedef struct { char p[12]; int w12; char q[2120]; void *w2136; } O_002C35C8;
void func_002C2D58(void *, int *); void func_002C3580(int);
// MATCH func_002C35C8
void FUN_002c35c8(O_002C35C8 *o, int b) { int t[2]; if (o->w2136 != 0 && o != 0 && o->w12 != 0) { t[1] = b; t[0] = 0; func_002C2D58(o->w2136, t); } else func_002C3580(b); }

typedef struct Q_002E8658 { int w0; char p[52]; struct Q_002E8658 *w56; } Q_002E8658;
typedef struct N_002E8658 { char p[8]; Q_002E8658 *w8; char q[8]; struct N_002E8658 *w20; } N_002E8658;
typedef struct { char p[40]; N_002E8658 *w40; } S_002E8658;
// MATCH func_002E8658
Q_002E8658 *FUN_002e8658(int a, S_002E8658 *s) { N_002E8658 *n; Q_002E8658 *q; for (n = s->w40; n != 0; n = n->w20) { for (q = n->w8; q != 0; q = q->w56) if (q->w0 == a) return q; } return 0; }

void func_002E58D0(int);
// MATCH func_002CB018
void FUN_002cb018(int a, int b, int c) { func_002E58D0(c); __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); }

void func_002E6750(int);
// MATCH func_002CDA58
void FUN_002cda58(int a, int b, int c) { func_002E6750(c); __asm__ volatile("sync"); __asm__ volatile(".word 0x42000038"); }


// MATCH func_002E6370
int FUN_002e6370(void) { int s; __asm__ volatile("mfc0 %0, $12" : "=r"(s)); return (s ^ 1) & 1; }


// MATCH func_002EDC98
int FUN_002edc98(void) { int s; __asm__ volatile("mfc0 %0, $12" : "=r"(s)); s = s & 0x10000; __asm__ volatile(".word 0x42000038"); return s != 0; }

