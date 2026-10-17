/* pchevent: Ghidra's decompilation of these functions, with only types and global
   names adjusted (tools/gen_ghidra.py); each compiles to the original bytes.
   Still to be cleaned up by hand. */
#include "../ghidra.h"

extern int D_002F9804[];
extern undefined * D_003C2770[];
extern uint D_004A140C;
extern int D_004A1444;
extern uint D_004A45E4;
extern int D_004A4678;
extern uint D_004A467C;
extern int D_004A4960;
extern uint D_004A67C4;
int FUN_001301e0(int *param_1, int param_2);
void FUN_00130260(int param_1, int param_2);
int FUN_0020b360(undefined8 param_1, undefined4 param_2);
uint FUN_0023a350(undefined8 param_1);
void FUN_002978e0(void);
void pchevent_0020b910(int param_1, int param_2, int param_3);
int pchevent_0020bbd8(int param_1);
void pchsysw_0012f840(undefined8 param_1, int param_2);

// MATCH func_0020BD00
undefined8 pchevent_0020bd00(int param_1)

{
  if (((param_1 != 0) && (D_004A1444 == 0)) && ((D_004A140C & 8) != 0)) {
    D_004A67C4 = 1;
    FUN_002978e0();
  }
  return 0;
}

#define DAT_002f9804 (D_002F9804[0])
// MATCH func_0020C8C8
undefined8 pchevent_0020c8c8(int param_1)

{
  int *piVar1;
  
  if (((param_1 != 0) && (D_004A1444 == 0)) && ((D_004A140C & 8) != 0)) {
    piVar1 = (int *)pchevent_0020bbd8(0);
    FUN_0020b360(DAT_002f9804,*piVar1 + 0x20);
  }
  return 0;
}
#undef DAT_002f9804

// MATCH func_0020CF48
void pchevent_0020cf48(int param_1)

{
  int lVar1;
  
  if ((((param_1 != 0) && (D_004A1444 == 0)) && ((D_004A140C & 8) != 0)) &&
     ((D_004A4678 != 0 && (lVar1 = FUN_001301e0(D_004A4678,D_004A467C), lVar1 != 0)))) {
    FUN_00130260(D_004A4678,D_004A467C);
    return;
  }
  return;
}

// MATCH func_0020CFA8
void pchevent_0020cfa8(int param_1)

{
  int lVar1;
  
  if ((((param_1 != 0) && (D_004A1444 == 0)) && ((D_004A140C & 8) != 0)) &&
     ((D_004A4678 != 0 && (lVar1 = FUN_001301e0(D_004A4678,D_004A467C), lVar1 != 0)))) {
    pchsysw_0012f840(D_004A4678,D_004A467C);
    return;
  }
  return;
}

// MATCH func_0020F050
undefined8 pchevent_0020f050(uint param_1)

{
  if ((param_1 & 8) != 0) {
    if (0 < D_004A4960) {
      pchevent_0020b910(D_004A45E4,D_004A4960,D_004A4960 + -1);
      D_004A4960 = D_004A4960 + -1;
    }
  }
  return 0;
}

// MATCH func_002102D0
void pchevent_002102d0(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &(D_003C2770[0]);
  do {
    FUN_0023a350(ppuVar1);
    ppuVar1 = ppuVar1 + 0xf;
  } while (ppuVar1 == &(D_003C2770[0]));
  return;
}
