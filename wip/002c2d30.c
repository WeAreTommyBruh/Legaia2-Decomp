// cflags: -fno-schedule-insns
#include "../src/common.h"
typedef struct { char pad[64]; char *a64; } S_2c2d30;
// 4 words differ
// WIP func_002C2D30
int FUN_002c2d30(S_2c2d30 *s, int i, int v, int w) { char *b = s->a64; int *p = (int *)(b + 12 + i * 8); int old; *(int *)(b + i * 8 + 16) = w; old = *p; *p = v; return old; }
