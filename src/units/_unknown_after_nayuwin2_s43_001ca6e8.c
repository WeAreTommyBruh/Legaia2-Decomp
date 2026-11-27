// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"
typedef struct { char p0[8]; int y; int f12; int idx; char p2[8]; int col; char p3[4]; void *tab; int f28; int id; char p4[206]; char fe; char ff; } E;
typedef struct { char p[360]; E *e; } O;
typedef struct { char p[6372]; char c[1]; } G;
extern G D_003FEBA8;
extern int D_004A3C58;
extern char D_004A3D80[];
int func_0025A508(void);
int *func_0025A5B8(void);
typedef struct { char * name; int a, b, c; } Q;
Q *func_0025A7D0(int);
void func_001302A8(char *, int, int);
int func_001A0A58(int);
void nayuwin2_001af938(O *, char *, int, int);
int nayuwin2_001ad850(O *);
void nayuwin2_001ad958(O *, int);
#define EI(i) ((E *)((i) * 256 + (int)o->e))
// MATCH func_001CA6E8
void FUN_001ca6e8(O *o)
{
    int i, n, m, k;
    int *ids;
    Q *q;
    char buf[128];
    for (k = 0; k < nayuwin2_001ad850(o); k++) {
        nayuwin2_001af938(o, D_004A3D80, k, 0);
        { E *e = EI(k); e->f28 = 0; e->id = -1; e->f12 = -1; e->idx = -1; }
    }
    m = 0;
    n = func_0025A508();
    ids = func_0025A5B8();
    for (k = 0; k < n; k++) {
        q = func_0025A7D0(*ids);
        if (D_003FEBA8.c[D_004A3C58] == q->c - 1) {
            { E *e = EI(m); e->f12 = 0; e->idx = m; e->y = m * 13 + 6; e->f28 = 1; e->id = *ids; func_001302A8(buf, (int)q->name, 128); }
            nayuwin2_001af938(o, buf, m, 0);
            if (func_001A0A58(*ids)) {
                E *e = EI(m); e->col = 0x787878; e->fe = 127;
            } else {
                E *e = EI(m); e->col = 0x404040; e->fe = 64;
            }
            m++;
        }
        ids++;
    }
    if (m > 0) nayuwin2_001ad958(o, o->e[m - 1].y);
    else nayuwin2_001ad958(o, o->e[0].y);
}
