/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { int x; } O_0010EC40; extern int D_00343028_0010EC40[] __asm__("D_00343028"); extern int D_004A3850_0010EC40 __asm__("D_004A3850"), D_004A118C_0010EC40 __asm__("D_004A118C"), D_004A12A4_0010EC40 __asm__("D_004A12A4"); extern char *D_004A12B0_0010EC40 __asm__("D_004A12B0"); extern char D_0042E6E0_0010EC40[] __asm__("D_0042E6E0"), D_0042E6F8_0010EC40[] __asm__("D_0042E6F8"); extern int D_002F95F0_0010EC40[] __asm__("D_002F95F0"), D_002F96B0_0010EC40[] __asm__("D_002F96B0"); void func_001118F8_0010EC40(char *, ...) __asm__("func_001118F8"); void func_0010E820_0010EC40(O_0010EC40 *, int) __asm__("func_0010E820"); void func_0010E938_0010EC40(int *, int) __asm__("func_0010E938");
// MATCH func_0010EC40
void FUN_0010ec40(O_0010EC40 *o, int f0) { int i; register int flag __asm__("$16") = f0; if (!(D_00343028_0010EC40[0] & 8) && D_004A3850_0010EC40 != 2) { if (D_004A118C_0010EC40 & 1) func_001118F8_0010EC40(D_0042E6E0_0010EC40); if (D_004A12A4_0010EC40 == 10) func_0010E820_0010EC40(o, 103); if (D_004A118C_0010EC40 & 0x40) func_001118F8_0010EC40(D_0042E6F8_0010EC40, D_004A12B0_0010EC40); if (flag != 0) { for (i = 0; i < 32; i++) { if (i != 1 && i != 2) func_0010E938_0010EC40(D_00343028_0010EC40, i); } {int prev = i - 1; __asm__ volatile("" : : "r"(prev));}} else { i = 3; do { func_0010E938_0010EC40(D_00343028_0010EC40, i); i++; } while (i < 32); } for (i = 0; i < 48; i++) { D_002F95F0_0010EC40[i] = -1; D_002F96B0_0010EC40[i] = -1; } } }
