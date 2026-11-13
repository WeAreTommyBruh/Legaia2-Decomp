/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int n; int *p[1]; } O_00204CD0; typedef struct { char p[528]; int w; } T_00204CD0;
// MATCH func_00204CD0
void pchjob0_00204cd0(O_00204CD0 *o) { if (o->n > 0) ((T_00204CD0 *)o->p[o->n - 1])->w = 0; }

void *func_002056A8(int, int, int);
// MATCH func_00205778
void pchjob0_00205778(int a, int b, int c, int d) { int *p = func_002056A8(a, b, c); if (p != 0) *p = d; }

void *func_002056A8(int, int, int);
// MATCH func_002057A8
void pchjob0_002057a8(int a, int b, int c, int d) { int *p = func_002056A8(a, b, c); if (p != 0) p[1] = d; }

typedef struct { int n; int a[1]; } S_204f30_00204F30;
void func_002044D8(int, int, int, int, int, int, void *); void func_00204A78(void);
// MATCH func_00204F30
void pchjob0_00204f30(S_204f30_00204F30 *s, int a, int b, int c, int d, int e) { if (s->n > 0) func_002044D8(s->a[s->n - 1], a, b, c, d, e, func_00204A78); }

typedef struct { int w0; char p[516]; int w520; char q[4]; int w528; } O_00204968;
int func_001AD6B0(int);
// MATCH func_00204968
void pchjob0_00204968(O_00204968 *o) { if (o->w0 != 0) { func_001AD6B0(o->w0); o->w0 = 0; o->w528 = 0; o->w520 = -1; } }

typedef struct { int w0; char p[524]; int w528; char q[8]; unsigned short h540[64]; } O_002049B0;
void func_001AD960(int, int, int, int);
// MATCH func_002049B0
void pchjob0_002049b0(O_002049B0 *o, int b) { int i; if (o->w0 != 0) { for (i = 0; i < o->w528; i++) { if (o->h540[i] == b) { func_001AD960(o->w0, i, o->w528, b); break; } } } }

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00205018;
typedef struct { char p[360]; R__00205018 *w360; } X__00205018;
typedef struct O__00205018 { X__00205018 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00205018;
typedef struct { int n; O__00205018 *it[1]; } L__00205018;
extern int D_00425710_00205018[] __asm__("D_00425710");
// MATCH func_00205018
void pchjob0_00205018(L__00205018 *l, int idx)
{
    O__00205018 *o;
    if (l->n > 0) {
        l->it[l->n - 1]->w524 = idx;
        o = l->it[l->n - 1];
        if (o->w0 != 0 && o->w528 > 0)
            D_00425710_00205018[idx] = o->w0->w360->w40;
    }
}

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00204D68;
typedef struct { char p[360]; R__00204D68 *w360; } X__00204D68;
typedef struct O__00204D68 { X__00204D68 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00204D68;
typedef struct { int n; O__00204D68 *it[1]; } L__00204D68;
int func_0025D858(int, int); void func_00203E30(O__00204D68 *, int, int, int, int);
// MATCH func_00204D68
void pchjob0_00204d68(L__00204D68 *l, int a, int b, int c, int d)
{
    if (func_0025D858(c, d) != 0 && l->n > 0) {
        O__00204D68 *o = l->it[l->n - 1];
        if (o->w528 < 64)
            func_00203E30(o, a, b, c, d);
    }
}


// MATCH func_002056A8
int pchjob0_002056a8(int *o, int x, int y) { if (x < -1 || y < -1 || o[4] < x || o[5] < y) return 0; { int a = x + 1; int b = y + 1; return o[7] + (a + b * (o[4] + 1)) * 8; } }

