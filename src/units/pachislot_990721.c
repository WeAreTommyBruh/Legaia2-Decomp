/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

// MATCH func_00166FD8
int pachislot_00166fd8(int *o, int k) { if (o[2] == 0 && k == 4) return 0; if (o[2] == 1 && k == 5) return 1; if (o[2] == 2 && k == 6) return 2; if (o[2] == 3 && k == 7) return 3; return -1; }

typedef struct { short delta; short index; union { int (*fn)(void *, int); short voff; } u_00168280;
} PMF;
extern char D_0043CCF0[]; extern char D_0043CD00[]; extern char D_0043CD10[]; extern int D_00334830[];
void func_001118F8_00168280() __asm__("func_001118F8");
#define PMFCALL(res, a) { int idx = f.index; int (*fn)(void *, int); long e; int dl; int d; if (idx > 0) { long *vt = *(long **)(o + f.u_00168280.voff); e = vt[idx - 1]; fn = (int (*)(void *, int))(e >> 32); } else fn = f.u_00168280.fn; dl = f.delta; d = idx > 0 ? (short)e + dl : dl; res = fn(o + d, a); }
// MATCH func_00168280
int pachislot_00168280(char *o, PMF f) { int i, k, r, a, b, c; i = 0; do { PMFCALL(r, i) if (r != 1) break; i++; } while (i < 6); if (i >= 6) return 0; func_001118F8_00168280(D_0043CCF0, i); a = -1; b = -1; c = -1; for (k = 5; i < k; k--) { PMFCALL(r, k) func_001118F8_00168280(D_0043CD00, k, D_00334830[r]); if (r == 2) a = k; if (r == 3) b = k; if (r == 4) c = k; } if (b >= 0) i = b; else if (a >= 0) i = a; else if (c >= 0) i = c; func_001118F8_00168280(D_0043CD10, i, a, b); return i; }
