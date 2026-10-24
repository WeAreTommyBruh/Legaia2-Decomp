#include "../src/common.h"
extern int D_004A45E4, D_004A4960; int func_002DCE40(char *, char *, ...); int func_0020B858(int, char *);
extern int D_004A45E8; extern int *D_004A6F78; extern char D_004551D0[];
typedef struct { char p[36]; float f36; } R; typedef struct { R *w0; } Q; Q *func_0020BBD8(int);
// 3 words differ
// WIP func_0020F640
int pchevent_0020f640(int f) { char buf[512]; Q *p; if (f & 8) { if (D_004A45E8 >= 0) { p = func_0020BBD8(D_004A45E8); if (p != 0) { float t = p->w0->f36; func_002DCE40(buf, D_004551D0, D_004A6F78[D_004A45E8], (double)t); func_0020B858(D_004A45E4, buf); D_004A4960++; } } } return 0; }
