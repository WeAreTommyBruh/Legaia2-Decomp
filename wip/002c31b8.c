// cflags: -fno-schedule-insns -fexceptions
#include "../src/common.h"
typedef struct { char pad[372]; int a372; } P_2c31b8;
typedef struct { char pad[64]; P_2c31b8 *a64; } S_2c31b8;
void func_002C3200(void *); void func_002C30A0(void *);
// 6 words differ
// WIP func_002C31B8
void FUN_002c31b8(S_2c31b8 *s) { if (s->a64->a372 != 3) func_002C3200(s); else func_002C30A0(s); }
