/* Functions of this report unit, matched by hand. */
#include "../common.h"

void func_001562E0_155A68(char *, int, int, int) __asm__("func_001562E0"); int func_00155D40_155A68(char *,float,int,int,float,float,float,float,float) __asm__("func_00155D40");
// MATCH func_00155A68
void sky_00155a68(char *o, int a1, int a2, int a3, int a4, int a5, float f1, float f2, float f3, float f4, float f5, float f6) { func_001562E0_155A68(o, a3, a4, a5); *(int *)(o + 144) = func_00155D40_155A68(o,f1,a1,a2,f2,f3,f4,f5,f6); }

