/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern char *D_00370B08_1A4180[] __asm__("D_00370B08"); extern int D_0036CBC0_1A4180[] __asm__("D_0036CBC0"); extern int D_0036CBE8_1A4180[] __asm__("D_0036CBE8"); extern char D_004443F0_1A4180[] __asm__("D_004443F0"); extern int D_004A6F6C_1A4180 __asm__("D_004A6F6C");
int func_0024A3C8_1A4180(char *, int *) __asm__("func_0024A3C8"); int func_001334D0_1A4180(int, char *, int) __asm__("func_001334D0");
// MATCH func_001A4180
void nayuini2_001a4180(void) { int i; if (D_004A6F6C_1A4180 != 0) { for (i = 0; i < 9; i++) D_0036CBC0_1A4180[i] = func_001334D0_1A4180(D_0036CBE8_1A4180[i], D_004443F0_1A4180, 43); } else { for (i = 0; i < 9; i++) D_0036CBC0_1A4180[i] = func_0024A3C8_1A4180(D_00370B08_1A4180[i], &D_0036CBE8_1A4180[i]); } D_004A6F6C_1A4180 = 1; }

