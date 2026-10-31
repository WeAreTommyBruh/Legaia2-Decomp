/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

extern int D_00343028[]; extern int D_004A3850, D_004A118C; extern char *D_004A12B0; extern char D_0042E718[], D_0042E740[]; extern int D_002F95F0[], D_002F96B0[]; void func_001118F8(char *, ...); void func_0010E820(int, int); void func_0010E938(int *, int);
// MATCH func_0010ED80
void FUN_0010ed80(int a) { int i; if (!(D_00343028[0] & 8) && D_004A3850 != 2) { if (D_004A118C & 0x40) func_001118F8(D_0042E718, D_004A12B0); if (D_004A118C & 1) func_001118F8(D_0042E740); func_0010E820(a, 103); for (i = 0; i < 32; i++) { if (i != 2) func_0010E938(D_00343028, i); } for (i = 0; i < 48; i++) { D_002F95F0[i] = -1; D_002F96B0[i] = -1; } } }

extern int D_00343028_0010EE78[] __asm__("D_00343028"); extern int D_004A3850_0010EE78 __asm__("D_004A3850"), D_004A118C_0010EE78 __asm__("D_004A118C"); extern char *D_004A12B0_0010EE78 __asm__("D_004A12B0"); extern char D_0042E750[], D_0042E778[]; extern int D_002F95F0_0010EE78[] __asm__("D_002F95F0"), D_002F96B0_0010EE78[] __asm__("D_002F96B0"); void func_001118F8(char *, ...); void func_0010E938(int *, int); void func_0010E428(int *); void func_002D38F8(void);
// MATCH func_0010EE78
void FUN_0010ee78(void) { int i; if (!(D_00343028_0010EE78[0] & 8) && D_004A3850_0010EE78 != 2) { if (D_004A118C_0010EE78 & 0x40) func_001118F8(D_0042E750, D_004A12B0_0010EE78); if (D_004A118C_0010EE78 & 1) func_001118F8(D_0042E778); for (i = 0; i < 32; i++) func_0010E938(D_00343028_0010EE78, i); for (i = 0; i < 48; i++) { D_002F95F0_0010EE78[i] = -1; D_002F96B0_0010EE78[i] = -1; } func_0010E428(D_00343028_0010EE78); func_002D38F8(); } }
