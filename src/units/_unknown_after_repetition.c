/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_00319660[]; void func_00247A48(int, long long); void func_00247B68(float, float); void func_00247E30(int);
// MATCH func_001775E0
void FUN_001775e0(int p1, int p2, short *p3) { unsigned long long a, b; float f; f = 128.0f; a = (unsigned long long)(long long)(D_00319660[p3[4]] + 0x3140) | 0x2000000000000000ULL; b = ((long long)(p3[5] * 4 + 0x3c00) << 0x25) | 0x6a9300000ULL; func_00247A48(6, (a | b) | 0x20000); func_00247B68((float)(int)*p3 * 0.0009765625f, (float)(int)p3[1] * 0.0009765625f); func_00247E30(p2); func_00247B68(((float)(int)*p3 + 84.0f) * 0.0009765625f, (float)(int)p3[1] * 0.0009765625f); func_00247E30(p2 + 0x10); func_00247B68((float)(int)*p3 * 0.0009765625f, ((float)(int)p3[1] + f) * 0.0009765625f); func_00247E30(p2 + 0x20); func_00247B68(((float)(int)*p3 + 84.0f) * 0.0009765625f, ((float)(int)p3[1] + f) * 0.0009765625f); func_00247E30(p2 + 0x30); }
