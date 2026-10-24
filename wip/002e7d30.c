#include "../src/common.h"
typedef struct { int a, b; } P_2e7d30;
extern P_2e7d30 *D_00632864, *D_0063286C;
// 8 words differ
// WIP func_002E7D30
void FUN_002e7d30(int i) { P_2e7d30 *t; if (i < 0) t = D_00632864; else t = D_0063286C; t[i].a = 0; }
