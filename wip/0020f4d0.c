#include "../src/common.h"
extern int D_004A45E4, D_004A4960; int func_002DCE40(char *, char *, ...); int func_0020B858(int, char *);
extern int D_004A45E8; extern int *D_004A6F78; extern char D_00455198[];
typedef struct { char p[32]; float f32; char p2[4]; float f40; } R; typedef struct { R *w0; } Q; Q *func_0020BBD8(int);
// 4 words differ
// WIP func_0020F4D0
int pchevent_0020f4d0(int f) { char buf[512]; Q *p; if (f & 8) { if (D_004A45E8 >= 0) { p = func_0020BBD8(D_004A45E8); if (p != 0) { func_002DCE40(buf, D_00455198, D_004A6F78[D_004A45E8], (double)p->w0->f32, (double)p->w0->f40); func_0020B858(D_004A45E4, buf); D_004A4960++; } } } return 0; }
