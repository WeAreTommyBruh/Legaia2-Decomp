/* Ghidra's decompilation, statement order searched by build/work/ghill.py. */
// cflags: -fexceptions
#include "../ghidra.h"
extern int D_0044B3D0[];
undefined8 akari_001e23b8(void);
#define DAT_0044b3d0 (D_0044B3D0[0])
// MATCH func_001D8250
int nayuki_001d8250(int param_1)

{
int iVar1;
akari_001e23b8(); iVar1 = (int)param_1; *(undefined4 *)(iVar1 + 0x80) = 0; *(undefined4 *)(iVar1 + 0x84) = 0; *(undefined4 *)(iVar1 + 0xd8) = 0x14; *(undefined **)(iVar1 + 100) = &DAT_0044b3d0; *(undefined4 *)(iVar1 + 0x104) = 0x3c; *(undefined4 *)(iVar1 + 0xdc) = 1; *(undefined4 *)(iVar1 + 0x108) = 0; *(undefined4 *)(iVar1 + 0x10c) = 1; *(undefined4 *)(iVar1 + 0x110) = 0; *(undefined4 *)(iVar1 + 0x214) = 0; *(undefined4 *)(iVar1 + 0xa04) = 0;
return param_1;
}
