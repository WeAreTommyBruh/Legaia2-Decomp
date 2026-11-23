/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern char D_00454CB8[]; void func_0020B4B8(char *, int); void func_00131588(char *); void func_00108B80(char *);
// MATCH func_00205600
void pchjob0_00205600(char *o, int flag) { char *a; char *p; *(int *)(o + 32) = (int)D_00454CB8; a = *(char **)(o + 28); if (a != 0) { p = a + (((int *)a)[-4] << 3); if (a != p) { do { p -= 8; func_0020B4B8(p, 0); } while (*(char **)(o + 28) != p); } func_00131588(*(char **)(o + 28) - 16); } if (flag & 1) func_00108B80(o); }

typedef struct { int a, x, y; int pad[7]; int w40; char pad2[212]; } R__00204F60;
typedef struct { char p[360]; R__00204F60 *w360; } X__00204F60;
typedef struct O__00204F60 { X__00204F60 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O__00204F60;
typedef struct { int n; O__00204F60 *it[1]; } L__00204F60;
extern X__00204F60 *D_004A3830;
void func_00204968(O__00204F60 *); void func_00203D38(O__00204F60 *, int);
// MATCH func_00204F60
void pchjob0_00204f60(L__00204F60 *l)
{
    if (l->n > 0) {
        l->n--;
        func_00204968(l->it[l->n]);
        if (l->it[l->n] != 0)
            func_00203D38(l->it[l->n], 3);
        if (l->n > 0)
            D_004A3830 = l->it[l->n - 1]->w0;
    }
}

typedef struct N__00205DD8 { struct N__00205DD8 *next; int p[3]; void (*fn)(void *); } N__00205DD8;
extern N__00205DD8 *D_002F9804[];
void func_00205C08(void *);
// MATCH func_00205DD8
void pchjob0_00205dd8(N__00205DD8 *p)
{
    N__00205DD8 *n;
    for (n = D_002F9804[0]; n != 0; n = n->next)
        if (n->fn == (void (*)(void *))func_00205C08) break;
    if (n == 0) {
        p->fn = (void (*)(void *))func_00205C08;
        func_00205C08(p);
    }
}

typedef struct { int a, x, y; int pad[7]; int w40[54]; } R_00205090;
typedef struct { char p[360]; R_00205090 *w360; } X_00205090;
typedef struct O_00205090 { X_00205090 *w0; int q[64]; int p[64]; int pad; int w520, w524, w528, w532, w536; unsigned short sh[64]; char b[64]; char t[64]; } O_00205090;
typedef struct { int n; O_00205090 *it[1]; } L_00205090;
extern int D_00425710[];


// MATCH func_00205090
void pchjob0_00205090(L_00205090 *l, int x, int y, int d) { O_00205090 *o; R_00205090 *r; int i, n, dx, dy; if (l->n > 0) { l->it[l->n - 1]->w536 = d; o = l->it[l->n - 1]; n = o->w528; if (o->w0 != 0 && n > 0) { r = o->w0->w360; dx = x - r->x; dy = y - r->y; for (i = 0; i < n; i++) { r->x += dx; r->y += dy; r++; } } } }
