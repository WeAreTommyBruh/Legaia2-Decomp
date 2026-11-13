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


// MATCH func_002CA8D8
int FUN_002ca8d8(void) { int t; __asm__ volatile("cfc2 %0, $29" : "=r"(t)); return (t & 0xf) == 1; }


// MATCH func_002CA8F0
void FUN_002ca8f0(void) { int t; __asm__ volatile("cfc2 %0, $28" : "=r"(t)); t |= 2; __asm__ volatile("ctc2 %0, $28" : : "r"(t)); }


// MATCH func_002CAA88
int FUN_002caa88(void) { int t; __asm__ volatile("cfc2 %0, $26" : "=r"(t)); return t & 0xffff; }


// MATCH func_002CAA38
int FUN_002caa38(void) { int t; __asm__ volatile("cfc2 %0, $29" : "=r"(t)); if (t & 2) return 1; if (t & 4) return 2; if (t & 8) return 3; return (t & 1) << 2; }


// MATCH func_002CAA18
int FUN_002caa18(void) { unsigned t; __asm__ volatile("cfc2 %0, $28" : "=r"(t)); return (t >> 2) & 1; }


// MATCH func_002CAA28
int FUN_002caa28(void) { unsigned t; __asm__ volatile("cfc2 %0, $28" : "=r"(t)); return (t >> 3) & 1; }


// MATCH func_002CA9B8
void FUN_002ca9b8(int on) { unsigned t; __asm__ volatile("cfc2 %0, $28" : "=r"(t)); if (on == 1) t |= 4; else t &= ~4; __asm__ volatile("ctc2 %0, $28" : : "r"(t)); }


// MATCH func_002CA9E8
void FUN_002ca9e8(int on) { unsigned t; __asm__ volatile("cfc2 %0, $28" : "=r"(t)); if (on == 1) t |= 8; else t &= ~8; __asm__ volatile("ctc2 %0, $28" : : "r"(t)); }

typedef struct { int a, b; } E8_002E7D30_2E7D30;
extern E8_002E7D30_2E7D30 *D_00632864_2E7D30[] __asm__("D_00632864"), *D_0063286C_2E7D30[] __asm__("D_0063286C");
// MATCH func_002E7D30
void FUN_002e7d30(int i) { register E8_002E7D30_2E7D30 *t __asm__("$4"); register int o __asm__("$3") = i << 3; if (i < 0) t = D_00632864_2E7D30[0]; else t = D_0063286C_2E7D30[0]; *(int *)(o + (int)t) = 0; }

