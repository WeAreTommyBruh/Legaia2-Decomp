/* Small functions matched by hand. */
// cflags: -O1
#include "common.h"

extern volatile int D_004A1444, D_004A140C; extern int D_004A46AC; void func_00212D50(int);
// MATCH func_0020D368
void pchevent_0020d368(int on) { if (on && D_004A1444 == 0 && (D_004A140C & 8) && D_004A46AC != 0) func_00212D50(D_004A46AC); }

typedef struct { char p[36]; int v; } O_00219838;
// MATCH func_00219838
int FUN_00219838(O_00219838 *o) { int v = o->v; if (v == 10) return 0; if (v == 30) return 0; if (v != 0) return 1; return 0; }

typedef struct { char p[16]; int w16; char q[4]; int w24; } S_002E8B18;
typedef struct { S_002E8B18 *s; int k; } P_002E8B18;
// MATCH func_002E8B18
int FUN_002e8b18(P_002E8B18 *p) { S_002E8B18 *q = p->s; if (q == 0 || p->k != q->w24 || (q->w16 & 1) == 0) return 0; return 1; }

typedef struct { char p[4]; int w4; } O_00166F90;
// MATCH func_00166F90
int pachislot_00166f90(O_00166F90 *o, int k) { if (o->w4 == 0) { if (k == 1) return 0; if (k == 2) return 0; } if (o->w4 == 1) { if (k == 3) return 1; } return -1; }

typedef struct { char p[12]; int w12; char q[2120]; void *w2136; } O_002C35C8;
void func_002C2D58(void *, int *); void func_002C3580(int);
// MATCH func_002C35C8
void FUN_002c35c8(O_002C35C8 *o, int b) { int t[2]; if (o->w2136 != 0 && o != 0 && o->w12 != 0) { t[1] = b; t[0] = 0; func_002C2D58(o->w2136, t); } else func_002C3580(b); }

typedef struct Q_002E8658 { int w0; char p[52]; struct Q_002E8658 *w56; } Q_002E8658;
typedef struct N_002E8658 { char p[8]; Q_002E8658 *w8; char q[8]; struct N_002E8658 *w20; } N_002E8658;
typedef struct { char p[40]; N_002E8658 *w40; } S_002E8658;
// MATCH func_002E8658
Q_002E8658 *FUN_002e8658(int a, S_002E8658 *s) { N_002E8658 *n; Q_002E8658 *q; for (n = s->w40; n != 0; n = n->w20) { for (q = n->w8; q != 0; q = q->w56) if (q->w0 == a) return q; } return 0; }
