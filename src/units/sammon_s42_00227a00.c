#include "../common.h"
extern char D_00343010[];
typedef struct { char p[24]; char q[1264 - 24]; int x[64]; int y[64]; } O;
int func_001E3E38(char *, int, int);
int func_002031F8(char *);
void func_001E28A0(char *, int, int, int);
int func_001E3890(char *, int, int);
// MATCH func_00227A00
int sammon_00227a00(O *o, int a, int b, int c) { int r; int i = func_002031F8(o->q); if (i < 0) return 0; r = func_001E3890(D_00343010, o->x[i], o->y[i]); func_001E3E38(D_00343010, r, 0); func_001E28A0(D_00343010, r, b, c); return r; }
