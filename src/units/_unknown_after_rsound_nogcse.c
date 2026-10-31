/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_00343028_0010D570[] __asm__("D_00343028"); extern int D_004A3850_0010D570 __asm__("D_004A3850"), D_004A118C_0010D570 __asm__("D_004A118C"); extern char *D_004A12B0_0010D570 __asm__("D_004A12B0"); extern char D_0042DF10[], D_0042DF28[]; void func_001118F8_0010D570(char *, ...) __asm__("func_001118F8"); int func_002D3B28(int, int, int); int func_002D3DF0(int, int);
// MATCH func_0010D570
int FUN_0010d570(int a, int b, int c, int d, int e, int *p9, int *p10) { int r; if ((D_00343028_0010D570[0] & 8) || D_004A3850_0010D570 == 2) return 0; if (D_004A118C_0010D570 & 1) func_001118F8_0010D570(D_0042DF10, b, c, d, e); if (D_004A118C_0010D570 & 0x40) func_001118F8_0010D570(D_0042DF28, D_004A12B0_0010D570); r = func_002D3B28(b, c, e); *p9 = r; *p10 = func_002D3DF0(r, d); return 1; }

extern int D_00343028_0010E368[] __asm__("D_00343028"); extern int D_004A3850_0010E368 __asm__("D_004A3850"), D_004A118C_0010E368 __asm__("D_004A118C"), D_004A12B0_0010E368 __asm__("D_004A12B0"), D_004A11DC, D_004A1188, D_004A11D4; extern int D_002F9598[]; extern char D_0042E490[], D_0042E4B0[]; void func_001118F8_0010E368(char *, ...) __asm__("func_001118F8"); void func_0010E2C0(int *, int); void func_002D5280(int);
// MATCH func_0010E368
void FUN_0010e368(int *o) { if (!(D_00343028_0010E368[0] & 8) && D_004A3850_0010E368 != 2) { if (D_004A118C_0010E368 & 1) func_001118F8_0010E368(D_0042E490, D_004A12B0_0010E368); if (D_004A118C_0010E368 & 0x40) func_001118F8_0010E368(D_0042E4B0, D_004A12B0_0010E368); func_0010E2C0(o, 0); func_002D5280(3); o[342] = 0; o[341] = 0; D_002F9598[0] = 0; D_002F9598[1] = 0; D_004A11DC = 0; D_004A1188 = 0; D_004A11D4 = 0;
o[337] = 0;
o[338] = 0;
o[336] = 0;
o[332] = 0; } }

extern int D_00343028_0010E1A0[] __asm__("D_00343028"); extern int D_004A3850_0010E1A0 __asm__("D_004A3850"), D_004A118C_0010E1A0 __asm__("D_004A118C"), D_004A11DC_0010E1A0 __asm__("D_004A11DC"); extern char *D_004A12B0_0010E1A0 __asm__("D_004A12B0"); extern int D_002F9598_0010E1A0[] __asm__("D_002F9598"); extern char D_0042E420[]; void func_001118F8_0010E1A0(char *, ...) __asm__("func_001118F8");
// MATCH func_0010E1A0
int FUN_0010e1a0(int *o, int x) { if ((D_00343028_0010E1A0[0] & 8) || D_004A3850_0010E1A0 == 2) return 0; if (D_002F9598_0010E1A0[0] == 0) return 0; if (o[332] != 0) return 0; if (D_004A118C_0010E1A0 & 1) func_001118F8_0010E1A0(D_0042E420, x, D_004A12B0_0010E1A0); if (D_00343028_0010E1A0[0] & 1) { D_004A11DC_0010E1A0 = 0; o[332] = 2; } return 1; }
