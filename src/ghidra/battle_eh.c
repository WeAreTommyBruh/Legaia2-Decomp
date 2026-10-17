/* battle_eh: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
// cflags: -fexceptions
#include "../ghidra.h"

extern int D_00431748[];
extern float D_0049FE0C;
extern int D_004A12A4;
extern uint D_004A13D4;
extern int D_004A1A20;
extern uint D_004A1A2C;
extern uint D_004A1A30;
extern uint D_004A1A64;
extern uint D_004A1A68;
extern int D_004A1A94;
extern uint D_004A1A9C;
extern uint D_004A1AA8;
extern uint D_004A6C24;
extern int D_004A6C40;
extern uint D_004A6C80;
extern int D_004A6CA4;
extern uint D_004A6CAC;
extern uint D_004A6CB0;
extern int D_004A6E30;
extern int D_0053FD00[];
int DbgPrintf(char *fmt);
void FUN_001100b8(void);
int FUN_00196ff8(void);
void FUN_001aa530(void);
float FUN_0021af68(int param_1);
void FUN_00237fe8(void);
int batread_0021f2a8(int param_1, int param_2, int param_3);
undefined4 battle_00127430(void);
bool battle_00127f70(void);
undefined4 battle_0012c1e8(void);

// MATCH func_00126038
bool battle_00126038(void)

{
  int lVar1;
  
  lVar1 = FUN_00196ff8();
  return lVar1 != 0;
}

// MATCH func_00126930
float battle_00126930(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)FUN_0021af68(D_004A1A20 + param_1 * 0x1560);
  fVar2 = (float)FUN_0021af68(D_004A1A20 + param_2 * 0x1560);
  return (fVar1 + fVar2) * 5120.0f * D_0049FE0C;
}

// MATCH func_00127580
bool battle_00127580(void)

{
  bool bVar1;
  int lVar2;
  
  if (D_004A12A4 == 0xb) {
    bVar1 = true;
  }
  else {
    lVar2 = battle_00127430();
    bVar1 = lVar2 != 0;
  }
  return bVar1;
}

#define DAT_0053fd00 (D_0053FD00[0])
// MATCH func_001275C0
undefined * battle_001275c0(void)

{
  undefined *puVar1;
  int lVar2;
  
  lVar2 = battle_0012c1e8();
  if (!(lVar2 == 0)) {
    puVar1 = &DAT_0053fd00;
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}
#undef DAT_0053fd00

// MATCH func_00127FE8
undefined4 battle_00127fe8(int param_1)

{
  int lVar1;
  
  if ((param_1 < 4) && (lVar1 = battle_00127f70(), lVar1 != 0)) {
    return 1;
  }
  return 0;
}

// MATCH func_00129B48
void battle_00129b48(void)

{
  FUN_00237fe8();
  D_004A6CB0 = 0;
  D_004A6CAC = 0;
  D_004A1A64 = 0;
  D_004A1A30 = 0;
  D_004A1A68 = 0;
  return;
}

#define DAT_00431748 (D_00431748[0])
// MATCH func_00129DE8
int battle_00129de8(void)

{
  int iVar1;
  
  iVar1 = DbgPrintf(&DAT_00431748);
  D_004A6C80 = 1;
  return iVar1;
}
#undef DAT_00431748

// MATCH func_0012ADF0
void battle_0012adf0(undefined4 param_1)

{
  int lVar1;
  
  lVar1 = battle_00127430();
  if (lVar1 == 0) {
    D_004A6C24 = param_1;
  }
  if (D_004A6E30 != 0) {
    *(undefined4 *)(D_004A1A94 + 0x14c) = 0;
    D_004A6E30 = 0;
  }
  return;
}

// MATCH func_0012AE68
undefined4 battle_0012ae68(void)

{
  int lVar1;
  
  if (((D_004A6C40 == 0) && (-1 < D_004A6CA4)) &&
     (lVar1 = batread_0021f2a8(D_004A1AA8,D_004A6CA4,1), lVar1 != 0)) {
    return 1;
  }
  return 0;
}

// MATCH func_0012AEA8
void battle_0012aea8(int param_1)

{
  if (param_1 == 2) {
    D_004A1A9C = 0;
  }
  FUN_001aa530();
  FUN_001100b8();
  D_004A13D4 = (int)param_1;
  D_004A1A2C = 10;
  return;
}
