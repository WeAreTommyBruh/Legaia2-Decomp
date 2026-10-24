#include "../src/common.h"
volatile int *func_002CFF38(void); void func_002D04C0(int, int, int, int);
// 4 words differ
// WIP func_002D3A08
void FUN_002d3a08(int a, unsigned b, unsigned c, unsigned d) { volatile int *p = func_002CFF38(); p[18] = p[18] + 1; func_002D04C0(a, (p[18] << 8) | ((b >> 16) & 0xff), (b << 16) | ((c >> 8) & 0xffff), (c << 24) | (d & 0xffffff)); }
