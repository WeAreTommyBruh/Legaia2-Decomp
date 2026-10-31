/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char pad[16]; int p; char p2[36]; int v; char p3[4]; } It_00130150;
typedef struct { int n; It_00130150 *a; } S_00130150;
// MATCH func_00130150
int FUN_00130150(S_00130150 *s, int i) { if (i >= s->n) return 0; if (s->a[i].p == 0) return 0; return s->a[i].v; }

typedef struct { int n; char *e; } L_12fbe8_0012FBE8;
// MATCH func_0012FBE8
int FUN_0012fbe8(L_12fbe8_0012FBE8 *l, int i) { int n = l->n; if (i >= n || *(int *)(l->e + i * 64 + 16) == 0) return n * 2; return *(int *)(l->e + i * 64 + 52); }

typedef struct { int n; char *e; } L_1301e0_001301E0;
// MATCH func_001301E0
int FUN_001301e0(L_1301e0_001301E0 *l, int i) { if (i >= l->n || *(int *)(l->e + i * 64 + 16) == 0) return 0; return *(int *)(l->e + i * 64 + 16); }

extern unsigned char *D_004A1B1C;
// MATCH func_00130B50
int FUN_00130b50(int x) { int lo = x & 0xff; int hi = (x >> 8) & 0xff; unsigned char *p = D_004A1B1C; int i = 0; do { if (hi == p[0]) if (lo == p[1]) return i + 376; i++; p += 2; } while (i < 48); return 0; }

typedef struct N_00131F10 { struct N_00131F10 *w0; struct N_00131F10 *w4; } N_00131F10;
extern N_00131F10 *D_004A3838, *D_004A383C; void func_00131F68(N_00131F10 *);
// MATCH func_00131F10
void FUN_00131f10(void) { N_00131F10 *p = 0; if (D_004A3838 != 0) { if (D_004A383C != 0) { do { if (p == 0) p = D_004A3838; else p = p->w4; func_00131F68(p); } while (p != D_004A383C); } } }

extern int D_004A14B0; extern char D_00314C20_00130C58[] __asm__("D_00314C20"); void func_00116820(char *, int); void func_00115C48(int, int, int, int, float, float, int, int); void func_00243688(void);
// MATCH func_00130C58
void FUN_00130c58(int a, int b, int c, float x, int d) { func_00116820(D_00314C20_00130C58, a); func_00115C48(a, b + 1, c, 0, x, x, D_004A14B0, d); func_00243688(); }
