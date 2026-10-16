/* battle: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_00327880[];
extern int D_003279A0[];
extern int D_0041AADC[];
extern int D_00431748[];
extern float D_0049FE0C;
extern int D_004A12A4;
extern int D_004A1A20;
extern uint D_004A1A30;
extern uint D_004A1A64;
extern uint D_004A1A68;
extern int D_004A1A94;
extern uint D_004A1AA8;
extern uint D_004A6C24;
extern int D_004A6C40;
extern int D_004A6C44;
extern uint D_004A6C80;
extern int D_004A6CA4;
extern uint D_004A6CAC;
extern uint D_004A6CB0;
extern uint D_004A6CD0;
extern uint D_004A6CD4;
extern uint D_004A6CD8;
extern uint D_004A6CDC;
extern uint D_004A6CE0;
extern uint D_004A6CE4;
extern uint D_004A6CF8;
extern uint D_004A6D00;
extern uint D_004A6D04;
extern uint D_004A6D08;
extern uint D_004A6D48;
extern uint D_004A6D4C;
extern uint D_004A6D50;
extern uint D_004A6D54;
extern uint D_004A6D58;
extern uint D_004A6D5C;
extern int D_004A6E30;
int DbgPrintf(char *fmt);
int FUN_00196ff8(void);
float FUN_0021af68(int param_1);
void FUN_00233178(void);
void FUN_00237fe8(void);
void FUN_00242b98(undefined4 param_1);
void FUN_00249108(void);
void FUN_002491d8(void);
void FUN_00249390(void);
int batread_0021f2a8(int param_1, int param_2, int param_3);
void battle_00118708(long param_1);
void battle_00126fa8(undefined8 param_1, undefined8 param_2, undefined8 param_3, undefined8 param_4, undefined8 param_5, undefined8 param_6);
undefined4 battle_00127430(void);
bool battle_00127f70(void);
void battle_0012aea8(int param_1);

// MATCH func_00119340
void battle_00119340(undefined8 param_1)

{
  FUN_00249390();
  FUN_00249108();
  battle_00118708(param_1);
  FUN_002491d8();
  return;
}

// MATCH func_0011DB78
uint battle_0011db78(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x1560 + D_004A1A20;
  return *(uint *)(*(int *)(iVar1 + 0x1378) * 0x9c + *(int *)(iVar1 + 0x1550)) & 1 ^ 1;
}

// MATCH func_00122118
void battle_00122118(void)

{
  FUN_00233178();
  battle_0012aea8(9);
  return;
}

// MATCH func_00126038
bool battle_00126038(void)

{
  int lVar1;
  
  lVar1 = FUN_00196ff8();
  return lVar1 != 0;
}

// MATCH func_00126810
void battle_00126810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  D_004A6D48 = param_1;
  D_004A6D5C = param_2;
  D_004A6D4C = param_3;
  D_004A6D50 = param_4;
  D_004A6D54 = param_5;
  D_004A6D58 = param_6;
  return;
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

// MATCH func_00127060
void battle_00127060(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  battle_00126fa8(0xffffffffffffffff,0xffffffffffffffff,param_1,param_2,param_3,param_4);
  return;
}

// MATCH func_001270E8
void battle_001270e8(undefined4 param_1,undefined4 param_2)

{
  D_004A6D04 = param_1;
  D_004A6D00 = 1;
  D_004A6D08 = param_2;
  return;
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

// MATCH func_001275F0
uint battle_001275f0(void)

{
  return D_004A6CF8 & 0xc;
}

// MATCH func_00127FC8
bool battle_00127fc8(int param_1)

{
  return *(int *)(param_1 * 0x1560 + D_004A1A20 + 0x1364) == 0x110;
}

// MATCH func_00127FE8
undefined4 battle_00127fe8(int param_1)

{
  int lVar1;
  
  if ((param_1 < 4) && (lVar1 = battle_00127f70(), lVar1 != 0)) {
    return 1;
  }
  return 0;
}

#define DAT_003279a0 (D_003279A0[0])
// MATCH func_00129650
bool battle_00129650(int param_1,int param_2)

{
  if ((*(uint *)(param_2 * 0x9c + *(int *)(param_1 * 0x1560 + D_004A1A20 + 0x1550)) & 1) != 0) {
    return false;
  }
  return (*(uint *)((&DAT_003279a0)[param_1] + 0xc0) & 0x24) == 0x24;
}
#undef DAT_003279a0

// MATCH func_001297A0
void battle_001297a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6)

{
  D_004A6CD0 = param_1;
  D_004A6CD4 = param_2;
  D_004A6CD8 = param_3;
  D_004A6CDC = param_4;
  D_004A6CE0 = param_5;
  D_004A6CE4 = param_6;
  return;
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

// MATCH func_0012A938
bool battle_0012a938(void)

{
  return D_004A6C44 != 0;
}

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

#define DAT_00327880 (D_00327880[0])
// MATCH func_0012AE58
void battle_0012ae58(void)

{
  DAT_00327880 = 0;
  return;
}
#undef DAT_00327880

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

// MATCH func_0012AEF0
void battle_0012aef0(int param_1)

{
  if ((((1 < param_1 - 0x72U) && (param_1 != 0xab)) && (param_1 != 0xac)) &&
     (((param_1 != 0x93 && (param_1 != 0x3a)) && (param_1 != 0x99)))) {
    return;
  }
  FUN_00242b98(1);
  return;
}

#define DAT_0041aadc (D_0041AADC[0])
// MATCH func_0012C960
void battle_0012c960(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  DAT_0041aadc = 0;
  iVar1 = 0x13;
  puVar2 = (undefined4 *)(D_004A1A20 + 0x1ab14);
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + -0x558;
  } while (-1 < iVar1);
  return;
}
#undef DAT_0041aadc
