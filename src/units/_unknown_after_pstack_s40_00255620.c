#include "../common.h"
void func_00255518(int, int);
// MATCH func_00255620
int FUN_00255620(int a) { int i, k; if ((unsigned)a >= 10) return -1; if (a < 5) { k = a * 16 + 1; for (i = 15; i >= 0; i--) { func_00255518(a, k); k++; } } else switch (a) { case 6: func_00255518(6, 81); break; case 7: func_00255518(7, 83); break; case 8: func_00255518(8, 85); func_00255518(8, 86); break; case 9: func_00255518(9, 89); break; } }
