// cflags: -fno-schedule-insns
#include "../src/common.h"
void func_002302B0(int); void func_00231580(float, float, int, int, int); void func_0022FDD8(void *); void func_002306E8(int, int, int, int); void func_00231548(void);
// 10 words differ
// WIP func_00230188
void FUN_00230188(int p, int i, int c, int d) { int h; func_002302B0(p); h = *(int *)(*(char **)((char *)p + 0x90) + 2052 + i * 4); if (h != 0) func_00231580(*(float *)((char *)p + 0x13c), *(float *)((char *)p + 0x140), p, h, (int)*(float *)((char *)p + 0x144)); func_0022FDD8((void *)p); func_002306E8(p, i, c, d); func_00231548(); }
