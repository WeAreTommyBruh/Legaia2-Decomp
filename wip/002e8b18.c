#include "../src/common.h"
typedef struct { int a0; int a4; } S_2e8b18; typedef struct { char pad[16]; int a16; char pad2[4]; int a24; } T_2e8b18;
// 7 words differ
// WIP func_002E8B18
int FUN_002e8b18(S_2e8b18 *s) { T_2e8b18 *p = (T_2e8b18 *)s->a0; if (p == 0) return 0; if (s->a4 != p->a24) return 0; if (p->a16 & 1) return 1; return 0; }
