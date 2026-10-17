/* srivus: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern char D_0033ADD8[];
extern char D_0033E7D0[];
extern int D_0043FBB8[];
extern int D_0043FC00[];
extern int D_0043FC48[];
extern int D_0043FC90[];
extern int D_0043FCD8[];
extern int D_0043FD20[];
extern int D_0043FD68[];
extern int D_0043FDB0[];
extern int D_0043FDF8[];
undefined8 FUN_00186ec8(void);
void FUN_00186f40(undefined8 param_1, int param_2, int param_3, int param_4);
void FUN_00187028(void);
void FUN_00231688(void);

#define DAT_0043fdf8 (D_0043FDF8[0])
// MATCH func_00187F58
int srivus_00187f58(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fdf8;
  return param_1;
}
#undef DAT_0043fdf8

// MATCH func_00187FD8
void srivus_00187fd8(undefined8 param_1)

{
  FUN_00187028();
  FUN_00186f40(param_1,((int)D_0033ADD8),0x14,0x16);
  return;
}

#define DAT_0043fdb0 (D_0043FDB0[0])
// MATCH func_00188010
int srivus_00188010(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fdb0;
  return param_1;
}
#undef DAT_0043fdb0

#define DAT_0043fd68 (D_0043FD68[0])
// MATCH func_001880D8
int srivus_001880d8(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fd68;
  return param_1;
}
#undef DAT_0043fd68

#define DAT_0043fd20 (D_0043FD20[0])
// MATCH func_001881A0
int srivus_001881a0(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fd20;
  return param_1;
}
#undef DAT_0043fd20

#define DAT_0043fcd8 (D_0043FCD8[0])
// MATCH func_00188268
int srivus_00188268(int param_1)

{
  FUN_00186ec8();
  *(undefined4 *)((int)param_1 + 0x4870) = 0;
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fcd8;
  return param_1;
}
#undef DAT_0043fcd8

#define DAT_0043fc90 (D_0043FC90[0])
// MATCH func_00188E68
int srivus_00188e68(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fc90;
  return param_1;
}
#undef DAT_0043fc90

// MATCH func_00188EE8
void srivus_00188ee8(undefined8 param_1)

{
  FUN_00187028();
  FUN_00186f40(param_1,((int)D_0033E7D0),0x18,0x1a);
  return;
}

#define DAT_0043fc48 (D_0043FC48[0])
// MATCH func_00188F20
int srivus_00188f20(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fc48;
  return param_1;
}
#undef DAT_0043fc48

#define DAT_0043fc00 (D_0043FC00[0])
// MATCH func_00188FF8
int srivus_00188ff8(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fc00;
  return param_1;
}
#undef DAT_0043fc00

// MATCH func_00189078
void srivus_00189078(int param_1)

{
  if ((*(uint *)(param_1 + 0x18) & 0x4000000) != 0) {
    FUN_00231688();
    return;
  }
  return;
}

#define DAT_0043fbb8 (D_0043FBB8[0])
// MATCH func_00189268
int srivus_00189268(int param_1)

{
  FUN_00186ec8();
  *(undefined **)((int)param_1 + 0x844) = &DAT_0043fbb8;
  return param_1;
}
#undef DAT_0043fbb8
