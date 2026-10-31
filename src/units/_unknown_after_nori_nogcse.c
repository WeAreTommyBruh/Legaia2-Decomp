/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_003FEBA8_00294220[] __asm__("D_003FEBA8");
// MATCH func_00294220
int FUN_00294220(int a) { D_003FEBA8_00294220[1] += a; if (D_003FEBA8_00294220[1] < 0) D_003FEBA8_00294220[1] = 0; if (D_003FEBA8_00294220[1] > 999999) D_003FEBA8_00294220[1] = 999999; return D_003FEBA8_00294220[1]; }

void func_00164A38(void *, int);
// MATCH func_00294560
void FUN_00294560(int *o, int a) { int i; a++; i = ((short *)o)[5] + a; if (i < 0) i += ((int *)o[0])[5]; if (i >= ((int *)o[0])[5]) i -= ((int *)o[0])[5]; func_00164A38(o, i); }
