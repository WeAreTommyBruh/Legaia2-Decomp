/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int a0, a4, a8, a12, a16, a20, a24; int a28; int a32; } T36_00218978;
extern T36_00218978 D_003C5BC8[]; void func_00216D28(void); void func_00229390(char *, int, int);
// MATCH func_00218978
void FUN_00218978(char *o) { int k; int u1, u2, u3, u4, u5, u6, u7; T36_00218978 *e; func_00216D28(); k = -1; if (*(int *)(o + 1780) == 0x17) k = 0; if (k >= 0) { e = &D_003C5BC8[k]; u1 = e->a0; u2 = e->a4; *(int *)(o + 60) = u1; *(int *)(o + 64) = u2; u3 = e->a24; u4 = e->a8; *(int *)(o + 2064) = u3; *(int *)(o + 68) = u4; u5 = e->a12; *(int *)(o + 2076) = u5; u6 = e->a16; *(int *)(o + 2080) = u6; u7 = e->a20; *(int *)(o + 2084) = u7; if (e->a28 != 0) func_00229390(o, e->a28, e->a32); } }
