/* Matched functions from this unit. */
#include "../common.h"

extern int D_004A3864; extern char D_0035A780[]; extern char D_0044C378[];
typedef struct { char p[80]; short h80; short h82; char p2[172]; } S_1e7cb0;
int func_002DCE40(char *, char *, ...); int func_001335E8(char *, int, int);
// MATCH func_001E7CB0
void FUN_001e7cb0(unsigned idx) { char buf[128]; S_1e7cb0 *e; short v; if (idx < 76) { do { e = (S_1e7cb0 *)D_0035A780 + idx; } while (0); if (e->h80 > 0) { e->h80--; if (D_004A3864 & 0x800) { func_002DCE40(buf, D_0044C378, idx, e->h80, e->h82); func_001335E8(buf, idx, 1); } } } }
