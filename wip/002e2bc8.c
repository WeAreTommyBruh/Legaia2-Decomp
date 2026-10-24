#include "../src/common.h"
typedef struct { char pad[16]; int a16; int a20; } S_2e2bc8;
S_2e2bc8 *func_002E2748(int, int);
// 7 words differ
// WIP func_002E2BC8
void FUN_002e2bc8(int a, int b) { S_2e2bc8 *p = func_002E2748(a, 1); p->a20 = b; p->a16 = 1; }
