// compiler: 991111-01
// cflags: -fexceptions
#include "../common.h"
int func_001F6080(int); int func_001F6078(int); int func_001F60A8(int);
void func_001F5EA0(int, int); void func_001F5F70(int, float);
// MATCH func_001F74A0
void ikumin_001f74a0(float f, char *o, int k) { int e = *(int *)(o + 176); while (func_001F6080(e) != k) { e = func_001F60A8(e); if (e == 0) return; } switch (func_001F6078(e)) { case 0: case 1: case 6: return; case 4: case 8: func_001F5F70(e, f); return; default: func_001F5EA0(e, (int)f); return; } }
