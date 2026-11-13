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

// compiler: 990721-r5900
// cflags: -fno-thread-jumps
extern int D_0043CCA8_167DD0[] __asm__("D_0043CCA8");
extern int D_0043CCC0_167DD0[] __asm__("D_0043CCC0");
extern int D_0043CCD8_167DD0[] __asm__("D_0043CCD8");
int DbgPrintf(char *fmt, ...);
int pachislot_00165a40(void *, int param_2);
int pachislot_00166fd8_167DD0(int param_1, int param_2) __asm__("pachislot_00166fd8");
#define DAT_0043cca8 (D_0043CCA8_167DD0[0])
#define DAT_0043ccc0 (D_0043CCC0_167DD0[0])
#define DAT_0043ccd8 (D_0043CCD8_167DD0[0])
// MATCH func_00167DD0
int pachislot_00167dd0(int param_1,int param_2)  { int iVar1; int uVar2; int lVar3; int lVar4;  lVar3 = pachislot_00166fd8_167DD0(param_1 + 8,6); iVar1 = *(int *)(param_1 + 0x168); uVar2 = 0; if (0 < iVar1) { lVar4 = pachislot_00165a40(param_1 + 0x2c,(int)param_2 + 1); if (lVar4 == 6) { DbgPrintf(&DAT_0043cca8,param_2); if (lVar3 != 2) { return 1; } uVar2 = 3; iVar1 = *(int *)(param_1 + 0x168); } else { iVar1 = *(int *)(param_1 + 0x168); } } if (1 < iVar1) { lVar4 = pachislot_00165a40(param_1 + 0x2c,(int)param_2 + 2); if (lVar4 == 6) { DbgPrintf(&DAT_0043ccc0,param_2); if (lVar3 != 2) { return 1; } uVar2 = 3; } lVar4 = pachislot_00165a40(param_1 + 0x2c,param_2); if (lVar4 == 6) { DbgPrintf(&DAT_0043ccd8,param_2); if (lVar3 != 2) { return 1; } uVar2 = 3; } } return uVar2; }
#undef DAT_0043cca8
#undef DAT_0043ccc0
#undef DAT_0043ccd8
