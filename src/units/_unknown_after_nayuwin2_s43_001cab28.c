// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"
typedef struct { char p0[8]; int y; int f12; int idx; char p2[8]; int col; char p3[4]; void *tab; int f28; int id; int f48; char p4[202]; char fe; char ff; } E;
typedef struct { char p[360]; E *e; } O;
typedef struct { char p[6372]; char c[308]; unsigned short tbl[1][236]; } G;
extern G D_003FEBA8;
extern int D_004A3C58;
extern char D_004A3C5C;
extern O *D_0036CAFC[];
extern char D_004A3D80[], D_00449DE8[];
char **func_0024F380(int);
void nayuwin2_001af938(O *, char *, int, int);
int nayuwin2_001ad850(O *);
void nayuwin2_001ad958(O *, int);
void nayuwin2_001af7b8(O *, int, int, int);
#define EI(i) ((E *)((i) * 256 + (int)o->e))
// MATCH func_001CAB28
void FUN_001cab28(O *o)
{
    int i, c;
    unsigned short *s;
    char **r;
    G *g;
    if (D_004A3C5C == 1) {
        for (i = 0; i < nayuwin2_001ad850(o); i++) {
            nayuwin2_001af938(o, D_004A3D80, i, 0);
            { E *e = EI(i); e->f28 = -1; e->id = -1; e->f12 = -1; e->idx = -1; }
        }
        return;
    }
    i = 0;
    c = D_003FEBA8.c[D_004A3C58];
    while (i < nayuwin2_001ad850(o)) {
        EI(i)->y = o->e[0].y + i * 13;
        g = &D_003FEBA8; { char *b = (char *)g->tbl; s = (unsigned short *)(b + (i * 2 + c * 472)); }


        if (*s == 0 || D_004A3C5C == 1) {
            nayuwin2_001af938(o, D_004A3D80, i, 0);
            { E *e = EI(i); int m = -1; e->f28 = m; e->id = m;
            if (i >= 4) {
                if (e[-1].f28 < 0 || o != D_0036CAFC[0]) {
                    e->f12 = m;
                    e->idx = m;
                } else {
                    nayuwin2_001af938(o, D_00449DE8, i, 0);
                    { E *e = EI(i); e->fe = 64; e->f28 = -10; e->id = 17; e->col = 0x404040; e->f12 = 0; e->idx = i; e->f48 = 0; }
                    nayuwin2_001ad958(o, EI(i)->y);
                }
            } }
        } else {
            r = func_0024F380(*s);
            { E *e = EI(i); e->fe = 127; e->col = 0x787878; e->idx = i; e->f12 = 0; }
            nayuwin2_001ad958(o, EI(i)->y);
            nayuwin2_001af938(o, r[0], i, 0);
            nayuwin2_001af7b8(o, i, *s, 0);
            nayuwin2_001af7b8(o, i, ((signed char *)r)[99], 1);
            nayuwin2_001af7b8(o, i, ((signed char *)r)[98], 2);
            nayuwin2_001af7b8(o, i, i, 3);
        }
        i++;
    }
}
