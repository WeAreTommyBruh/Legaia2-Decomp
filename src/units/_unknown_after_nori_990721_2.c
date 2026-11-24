/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

extern char *D_004A1A20_282960 __asm__("D_004A1A20");
extern int D_00314CC8_282960[] __asm__("D_00314CC8");
extern int D_00314D08_282960[] __asm__("D_00314D08");
extern int D_004A66C4_282960 __asm__("D_004A66C4");
int func_00291C20_282960(int, int, int) __asm__("func_00291C20");
// MATCH func_00282960
int FUN_00282960(int a) { int r; if (a >= 4 || (*(unsigned *)(D_004A1A20_282960 + a * 5472 + 4816) & 1) != 0) return 0; if (D_00314CC8_282960[0] == 100 && D_00314D08_282960[a] == 1) { r = 10; if ((D_004A66C4_282960 & 8) == 0) r = 0; return r; } return func_00291C20_282960(*(int *)(D_004A1A20_282960 + a * 5472 + 4800), 10, 0); }


extern int D_004A65DC_27C308 __asm__("D_004A65DC"), D_004A65B8_27C308 __asm__("D_004A65B8"), D_004A65D0_27C308 __asm__("D_004A65D0"), D_004A65D4_27C308 __asm__("D_004A65D4"), D_004A65D8_27C308 __asm__("D_004A65D8"), D_004A5E44_27C308 __asm__("D_004A5E44"), D_004A7288_27C308 __asm__("D_004A7288"), D_004A7274_27C308 __asm__("D_004A7274");
extern char *D_004A1A20_0027C308 __asm__("D_004A1A20");
int func_0027C428_27C308(void) __asm__("func_0027C428");
// MATCH func_0027C308
int FUN_0027c308(void) { int i, t, s; D_004A65B8_27C308 = (D_004A65B8_27C308 + 1) & 1; D_004A65D0_27C308 = -1; D_004A65D4_27C308 = -1; D_004A65D8_27C308 = -1; D_004A65DC_27C308 = -1; D_004A5E44_27C308 = 0; i = func_0027C428_27C308(); D_004A7288_27C308++; if (D_004A7274_27C308 == 0) D_004A7274_27C308 = 1; if (*(int *)(D_004A1A20_0027C308 + i * 5472 + 5416) >= 0) { s = *(int *)(D_004A1A20_0027C308 + i * 5472 + 4980); if (s == 25 || s == 38 || s == 41 || s == 44 || s == 47) { t = *(int *)(D_004A1A20_0027C308 + i * 5472 + 5416); *(int *)(D_004A1A20_0027C308 + i * 5472 + 5416) = -1; *(int *)(D_004A1A20_0027C308 + t * 5472 + 5416) = i; i = t; } } return i; }
