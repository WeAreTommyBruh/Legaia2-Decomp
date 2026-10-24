#include "../src/common.h"
typedef struct { char pad[372]; unsigned short a[1200]; unsigned char b[1200]; } T_250c60;
extern unsigned short D_00401028[]; extern T_250c60 D_003FEBA8;
// 11 words differ
// WIP func_00250C60
int FUN_00250c60(unsigned i) { int idx = D_00401028[i]; int v = D_003FEBA8.a[idx]; if (v >= 301) return D_003FEBA8.b[idx]; if (v == 0) return 0; return D_003FEBA8.b[idx] != 0; }
