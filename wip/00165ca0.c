#include "../src/common.h"
typedef struct { char pad[12]; int a12; char pad2[36]; int a52; } S_165ca0;
extern char D_0043C8D0[];
int func_001118F8();
// 2 words differ
// WIP func_00165CA0
int pachislot_00165ca0(S_165ca0 *s, int b) { int r = func_001118F8(D_0043C8D0); s->a52 = b; s->a12 = -1; return r; }
