#include "../src/common.h"
typedef struct { int a0; int a4; int a8; int a12; } S_2153a8;
void func_00214A68(void *, int, int, int);
// 4 words differ
// WIP func_002153A8
void FUN_002153a8(S_2153a8 *s) { s->a12 = 0x80787878; func_00214A68(s, *(int *)s->a4, 0, 0); }
