/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { short delta; short index; union { int (*fn)(void *, int **); short voff; } u_00163E68;
} PMF;
extern PMF D_00333A50[];
// MATCH func_00163E68
int FUN_00163e68(char *o, int **pp) { int op; int r; do { int idx; int (*fn)(void *, int **); long e; int dl; int d; op = *(*pp)++; idx = D_00333A50[op].index; if (idx > 0) { long *vt = *(long **)(o + D_00333A50[op].u_00163E68.voff); e = vt[idx - 1]; fn = (int (*)(void *, int **))(e >> 32); } else fn = D_00333A50[op].u_00163E68.fn; dl = D_00333A50[op].delta; d = idx > 0 ? (short)e + dl : dl; r = fn(o + d, pp); } while (r == 0); return op == 13; }
