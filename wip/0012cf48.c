// cflags: -O1
#include "../src/common.h"
typedef struct { int w0; int w4; char p[1180]; int w1188; } B; extern B * volatile D_004A1A3C;
// 9 words differ
// WIP func_0012CF48
int FUN_0012cf48(void) { B *p = D_004A1A3C; int r = 0; if (p != 0) { if (p->w4 >= 100) r = p->w1188 == 0; } return r; }
