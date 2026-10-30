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

typedef struct { char p[12]; unsigned w12; } P_0029D0B8;
typedef struct { char p[16]; P_0029D0B8 *w16; } O_0029D0B8;
void func_0029D378(O_0029D0B8 *); void func_0029D200(O_0029D0B8 *); void func_0029D120(O_0029D0B8 *);
// MATCH func_0029D0B8
int clas_min_0029d0b8(O_0029D0B8 *o) { P_0029D0B8 *p = o->w16; unsigned f; if (p == 0) return 0; f = p->w12; if (f & 8) { func_0029D378(o); return 1; } if (f & 1) { func_0029D200(o); return 1; } func_0029D120(o); return 1; }

typedef struct { char p[24]; unsigned w24; } P_0029CA78;
typedef struct { char p[28]; P_0029CA78 *w28; } O_0029CA78;
void func_0029CBF0(O_0029CA78 *); void func_0029CD90(O_0029CA78 *, int, int); void func_0029CAF8(O_0029CA78 *);
// MATCH func_0029CA78
int clas_min_0029ca78(O_0029CA78 *o, int a) { P_0029CA78 *p = o->w28; unsigned f; if (p == 0) return 0; f = p->w24; if (f & 1) { func_0029CBF0(o); return 1; } if (f & 4) { func_0029CD90(o, a, 10000); return 1; } if (f & 16) { func_0029CD90(o, a, 50000); return 1; } func_0029CAF8(o); return 1; }

typedef struct { char b0; char p[23]; int w24; } E_0025D0F0;
extern E_0025D0F0 D_003E2010[]; extern char D_0047B0E0[];
// MATCH func_0025D0F0
int FUN_0025d0f0(int a) { E_0025D0F0 *p = D_003E2010; E_0025D0F0 *e = p + 253; do { if (p->b0 == a) return p->w24; p++; } while (p < e); return (int)D_0047B0E0; }

extern unsigned short D_004A5990, D_004A5992; void func_002552B8(void);
// MATCH func_00255278
void FUN_00255278(unsigned a) { if (a < 9) { if (a == 7) D_004A5992 = D_004A5990; if (a == 8) D_004A5990 = D_004A5992; else D_004A5990 = a; func_002552B8(); } }

typedef struct N_001624E0 { int a[3]; struct N_001624E0 *n; } N_001624E0;
// MATCH func_001624E0
N_001624E0 *FUN_001624e0(char *o) { N_001624E0 *p = *(N_001624E0 **)(o + 56); if (p != 0 && p->n != 0) { do { p = p->n; } while (p->n != 0); } return p; }

void func_00192EB0(int, int, int, int); void func_00193590(int, int, int, int); void func_00193D28(int, int, int, int);
// MATCH func_001947A8
void FUN_001947a8(int a, int k, int p, int q, int r) { switch (k) { case 0: func_00192EB0(a, p, q, r); break; case 2: func_00193590(a, p, q, r); break; case 1: func_00193D28(a, p, q, r); break; } }

void func_0018A658(char *, char *); char *func_002DD1DC(char *, int); char *func_0018A708(char *);
// MATCH func_0018B1F8
int FUN_0018b1f8(char *name) { char buf[256]; char *p, *e; if (name == 0) return -1; func_0018A658(name, buf); p = func_002DD1DC(buf, 58); if (p == 0) p = buf; else p++; e = func_0018A708(p); if (e == 0) return -1; return ((unsigned short *)e)[5] << 11; }

// MATCH func_001577C0
void FUN_001577c0(float *a, float *b) { for (;;) { int n; if (b[74] <= a[74]) { n = ((int *)a)[75]; if (n == 0) { ((int *)a)[75] = (int)b; return; } } else { n = ((int *)a)[76]; if (n == 0) { ((int *)a)[76] = (int)b; return; } } a = (float *)n; } }

typedef struct N__00212C18 { struct N__00212C18 *next; int w4, w8, w12; struct N__00212C18 *w16; } N__00212C18;
typedef struct { int w0; int w4; N__00212C18 *w8; } O__00212C18;
void func_0010E820(int, int);
// MATCH func_00212C18
int FUN_00212c18(O__00212C18 *o, int n, int m)
{
    N__00212C18 *p, *q;
    int i;
    p = o->w8;
    i = 0;
    if (p == 0) return 0;
    if (n != 0) {
        do {
            p = p->next;
            if (p == 0) break;
            i++;
        } while (i != n);
    }
    if (p == 0) return 0;
    q = p->w16;
    i = 0;
    if (q == 0) return 0;
    if (m != 0) {
        do {
            q = q->next;
            if (q == 0) break;
            i++;
        } while (i != m);
    }
    if (q == 0) return 0;
    func_0010E820(o->w0, 103);
    return 1;
}

typedef struct { char c[33]; } S33__002224A8;
extern char D_00459CF0[]; extern char D_00321060[]; extern int D_00326F90[];
// MATCH func_002224A8
void FUN_002224a8(int a, int b, int c, int d)
{
    if (a != 0) {
        *(S33__002224A8 *)D_00321060 = *(S33__002224A8 *)D_00459CF0;
    }
    D_00326F90[0] = a;
    D_00326F90[3] = c;
    D_00326F90[8] = d;
    D_00326F90[13] = 0;
}

// MATCH func_002A43A8
int clas_min_002a43a8(int *p, int n) { int i; for (i = 0; i < n && p != 0; i++) p = (int *)p[0]; if (p == 0) return -1; return p[1]; }

extern int *D_004A3838;
// MATCH func_001E2678
int akari_001e2678(int a, int *b) {
    int *p;
    for (p = D_004A3838; p != 0; p = (int *)p[1]) if (p == b) return 1;
    return 0;
}

// MATCH func_002A1DF8
int clas_min_002a1df8(char *o, int key) { char *p; if (key == -1) return *(int *)(o + 1616) == 0; p = *(char **)(o + 1616); while (p != 0) { if (*(int *)(p + 260) == key) break; p = *(char **)(p + 256); } return p == 0; }

extern int D_004A14CC; extern char D_00440530[];
int func_0024C568(void *); unsigned long long func_001118F8(char *, ...);
// MATCH func_0018BB70
int FUN_0018bb70(int *a, int b, int c, int d, int e, int idx) { if ((unsigned)a & 0xf) D_004A14CC++; if (idx >= 0) { if ((unsigned)idx < (unsigned)a[0]) { if (func_0024C568((char *)a + (a[idx + 1] << 2)) < 0) func_001118F8(D_00440530); } } return -1; }
