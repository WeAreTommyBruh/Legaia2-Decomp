// compiler: 991111-01-as210
// cflags: -fno-gcse
#include "../common.h"
void func_001D9980(int); void func_001E2528(int); void func_001D8478(int, int); void func_001E24A8(int, int); void func_001EAA38(int);
// MATCH func_00131F68
void FUN_00131f68(char *o) { int i; int *p; int t; i = 0; *(int *)(o + 292) = 0; for (; i < *(int *)(o + 300); i++) { p = (int *)(o + 304) + i; switch (p[64]) { case 1: t = p[0]; func_001D9980(t); func_001E2528(t); func_001D8478(t, 0); func_001E24A8(t, 1); break; case 2: t = p[0]; func_001E2528(t); func_001E24A8(t, 1); break; case 3: t = p[0]; func_001EAA38(t); func_001E2528(t); func_001E24A8(t, 1); break; } } }
