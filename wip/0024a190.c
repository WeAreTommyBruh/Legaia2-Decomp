// cflags: -fno-schedule-insns
#include "../src/common.h"
typedef struct N { int a; struct N *b; int c; int d; struct N *e; } N; extern int D_002F9800[];
// 8 words differ
// WIP func_0024A190
N *FUN_0024a190(void) { int n = D_002F9800[0]; N *p = (N *)D_002F9800[4 + n]; D_002F9800[0] = n - 1; p->a = 0; p->b = p; p->e = p; return p; }
