/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { int a, x, y; int pad[7]; int w40[54]; } R_00205218;
typedef struct { char p[360]; R_00205218 *w360; } X_00205218;
typedef struct O_00205218 { X_00205218 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O_00205218;
typedef struct { int n; O_00205218 *it[1]; } L_00205218;
extern int D_00425710_205218[] __asm__("D_00425710");


// MATCH func_00205218
void pchjob0_00205218(L_00205218 *l, int idx, int key, int a, int b, int c) { O_00205218 *o; int i, n; unsigned short *p; if (idx < l->n) { o = l->it[idx]; n = o->w528; i = 0; if (n > 0) { p = o->sh; while (key != *p) { i++; if (i >= n) return; p++; } o = l->it[idx]; if (i < o->w528) D_00425710_205218[b] = o->w0->w360[i + c].w40[a]; } } }

typedef struct { int a, x, y; int pad[7]; int w40[54]; } R_002052C0;
typedef struct { char p[360]; R_002052C0 *w360; } X_002052C0;
typedef struct O_002052C0 { X_002052C0 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O_002052C0;
typedef struct { int n; O_002052C0 *it[1]; } L_002052C0;
extern int D_00425710_002052C0[] __asm__("D_00425710");


// MATCH func_002052C0
void pchjob0_002052c0(L_002052C0 *l, int idx, int key, int a, int b, int c) { O_002052C0 *o; int i, n; unsigned short *p; if (idx < l->n) { o = l->it[idx]; n = o->w528; i = 0; if (n > 0) { p = o->sh; while (key != *p) { i++; if (i >= n) return; p++; } o = l->it[idx]; if (i < o->w528) o->w0->w360[i + c].w40[a] = D_00425710_002052C0[b]; } } }

typedef struct { int a, x, y; int pad[7]; int w40[54]; } R_00205368;
typedef struct { char p[360]; R_00205368 *w360; } X_00205368;
typedef struct O_00205368 { X_00205368 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O_00205368;
typedef struct { int n; O_00205368 *it[1]; } L_00205368;
extern int D_00425710_00205368[] __asm__("D_00425710");

int func_0012D3D8_205368(int) __asm__("func_0012D3D8"); void func_001AF908_205368(X_00205368 *, int, int) __asm__("func_001AF908");
// MATCH func_00205368
void pchjob0_00205368(L_00205368 *l, int idx, int key, int v, int e) { O_00205368 *o; int i, n; unsigned short *p; if (idx >= l->n) return; o = l->it[idx]; n = o->w528; i = 0; if (n <= 0) return; p = o->sh; while (key != *p) { i++; if (i >= n) return; p++; } if (i >= l->it[idx]->w528) return; l->it[idx]->b[i + e] = v; func_001AF908_205368(l->it[idx]->w0, i + e, func_0012D3D8_205368(v)); }

