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
