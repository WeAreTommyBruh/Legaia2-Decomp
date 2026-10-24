#include "../src/common.h"
extern int D_004A45E4, D_004A4960; int func_002DCE40(char *, char *, ...); int func_0020B858(int, char *);
extern int D_004A46AC, D_004A46BC; extern char D_00455308[], D_00455318[]; int func_00212968(int, int *, int *, int *, int);
// 2 words differ
// WIP func_0020FD88
int pchevent_0020fd88(int f) { char buf[512]; int a, b, c; if (f & 8) { if (D_004A46AC != 0 && D_004A46BC >= 0) {  if ((c = -1, func_00212968(D_004A46AC, &a, &b, &c, D_004A46BC) != 0)) { func_002DCE40(buf, D_00455308, a); func_0020B858(D_004A45E4, buf); D_004A4960++; func_002DCE40(buf, D_00455318); func_0020B858(D_004A45E4, buf); D_004A4960++; } } } return 0; }
