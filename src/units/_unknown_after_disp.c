/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern float D_004A0680; void func_00235138(float);
// MATCH func_00235130
void FUN_00235130(void) { func_00235138(D_004A0680); }

extern float D_004A0670; extern int D_004A14B8_00231E30 __asm__("D_004A14B8"); void func_0018E860(float *, float, float, float); void func_0018F3D8_00231E30(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00231E30(float *, float *) __asm__("func_0018DF68");
// MATCH func_00231E30
void FUN_00231e30(int a, int b, int c) { func_0018E860((float *)0x70003f00, a * D_004A0670, b * D_004A0670, c * D_004A0670); func_0018F3D8_00231E30((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00231E30((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00231E30 != 0) { func_0018DF68_00231E30((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00231E30((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

void func_00235338(float, float, float, float, int, int, int, int, int, int, int, int, int, int, int);
// MATCH func_00235680
void FUN_00235680(float a, float b, int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10) { func_00235338(a, b, 1.0f, 1.0f, i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }

