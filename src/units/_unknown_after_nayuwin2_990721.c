/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { char p0[8]; int y; char p1[4]; int idx; char p2[8]; int col; char p3[4]; void *tab; int f28; int id; int type; char p4[202]; char fe; char ff; } E_1ca480;
typedef struct { char p[360]; E_1ca480 *e; } O_1ca480;
typedef struct { char p[6372]; char c[1]; } G_1ca480;
extern G_1ca480 D_003FEBA8;
extern int D_004A3C58;
extern char D_0036A2EC[], D_0036A3C0[], D_00365AE0[], D_00449DC8[], D_004A3D80[];
int func_0025B7F0(int);
int *func_0025B910(int);
int func_0025B6E0(int, int);
char *func_0025B170(int, int);
void nayuwin2_001af938(O_1ca480 *, char *, int, int);
int nayuwin2_001ad850(O_1ca480 *);
void nayuwin2_001ad958(O_1ca480 *, int);
#define EI(i) ((E_1ca480 *)((i) * 256 + (int)o->e))
// MATCH func_001CA480
void FUN_001ca480(O_1ca480 *o) { int c, n, i, t; int *ids; c = D_003FEBA8.c[D_004A3C58]; n = func_0025B7F0(c); ids = func_0025B910(c); for (i = 0; i < n; i++) { t = func_0025B6E0(c, *ids); nayuwin2_001af938(o, func_0025B170(c, *ids), i, 0); if (t == 10) { E_1ca480 *e = EI(i); e->col = 0x404040; e->fe = 64; EI(i)->tab = D_0036A3C0; } else { E_1ca480 *e = EI(i); e->col = 0x787878; e->fe = 127; EI(i)->tab = D_0036A2EC + t * 212; } { E_1ca480 *e = EI(i); e->f28 = 1; e->id = *ids; e->idx = i; ids++; e->y = i * 13 + 6; e->type = t; } } for (i = n; i < nayuwin2_001ad850(o); i++) { if (i == 0) { nayuwin2_001af938(o, D_00449DC8, 0, 0); o->e[0].tab = D_00365AE0; } else { nayuwin2_001af938(o, D_004A3D80, i, 0); EI(i)->tab = 0; } EI(i)->f28 = -1; EI(i)->idx = -1; } if (n > 0) nayuwin2_001ad958(o, o->e[n - 1].y); else nayuwin2_001ad958(o, o->e[0].y); }
