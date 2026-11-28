// compiler: 990721-r5900
#include "../common.h"
typedef unsigned long long U64_57B0;
typedef struct { char p[16]; void *w16; } P_57B0;
extern char D_003187C0[], D_00342D00[], D_0041EFB0[]; extern P_57B0 D_00342CD0; extern int D_00343654[]; extern long long D_004A12D8; extern void *D_002F9800[];
void func_00155000(void *); void func_00195908(void); void func_00154428(void *); void func_0018EB98(int, void *); void func_002489F0(void); void func_00248A58(int);
void func_00190328(P_57B0 *); void func_00190420(P_57B0 *); void func_001B4738(int, int, int, int); void func_001AA538(void); void func_001AB800(void); void func_00246AD0(void *); void func_00246B98(void *);
// MATCH func_001957B0
void FUN_001957b0(void) { U64_57B0 *q;
  D_003187C0[384] = 32; D_003187C0[752] = 32; D_003187C0[385] = 32; D_003187C0[753] = 32; D_003187C0[386] = 32; D_003187C0[754] = 32;
  func_00155000(D_00342D00); func_00195908(); func_00154428(D_0041EFB0); func_0018EB98(0x70003c00, D_0041EFB0 + 128); func_002489F0(); func_00248A58(0x70003f80); func_00248A58(0x70003d80);
  func_00190328(&D_00342CD0);
  q = (U64_57B0 *)D_00342CD0.w16; q[0] = 0x808080; q[1] = 61; q[2] = 68; q[3] = 66; q[4] = 0x5000d; q[5] = 71; q[6] = 0xff00000000000000ULL; q[7] = 10; D_00342CD0.w16 = (void *)(q + 8);
  func_00190420(&D_00342CD0);
  if (D_00343654[0] == 0 && (D_004A12D8 & 0x20)) func_001B4738(0, 1, 1, 0);
  func_001AA538(); func_001AB800();
  func_00246AD0(D_002F9800[1]); func_00246AD0(D_002F9800[2]); func_00246B98(D_002F9800[1]); func_00246B98(D_002F9800[2]); }
