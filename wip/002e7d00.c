#include "../src/common.h"
typedef struct { int a, b; } P_2e7d00;
extern P_2e7d00 *D_00632864, *D_0063286C;
// 9 words differ
// WIP func_002E7D00
void FUN_002e7d00(int i, int a, int b) { P_2e7d00 *t; if (i < 0) t = D_00632864; else t = D_0063286C; t[i].a = a; t[i].b = b; }
