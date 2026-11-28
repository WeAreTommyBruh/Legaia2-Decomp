// compiler: 990721-r5900
#include "../common.h"
extern void *D_0036CAB0[]; extern int D_004A382C, D_004A12A4; extern char D_00343028[];
void func_001AE398(void *); void func_001AD888(void *, int); int func_001AD810(void *); int func_001AD838(void *); void func_001B4B40(int); void func_0010C2B0(void *, int, int, int, int, int, int); void func_001B4738(int, int, int, int); void func_0029B450(char *);
// MATCH func_001A0720
void FUN_001a0720(void) { char buf[16];
  func_001AE398(D_0036CAB0[6]); func_001AD888(D_0036CAB0[6], 30);
  func_001AE398(D_0036CAB0[5]); func_001AD888(D_0036CAB0[5], 30);
  func_001AE398(D_0036CAB0[4]); func_001AD888(D_0036CAB0[4], 30);
  func_001AE398(D_0036CAB0[3]); func_001AD888(D_0036CAB0[3], 30);
  func_001AE398(D_0036CAB0[2]); func_001AD888(D_0036CAB0[2], 30);
  func_001AE398(D_0036CAB0[1]); func_001AD888(D_0036CAB0[1], 30);
  func_001AE398(D_0036CAB0[0]); func_001AD888(D_0036CAB0[0], 30);
  if (func_001AD810(D_0036CAB0[7]) && func_001AD838(D_0036CAB0[7]) <= 0) { func_001AE398(D_0036CAB0[7]); func_001AD888(D_0036CAB0[7], 30); func_001AE398(D_0036CAB0[8]); func_001AD888(D_0036CAB0[8], 30); }
  func_001B4B40(D_004A382C);
  func_0010C2B0(D_00343028, 0, 2, 0, 2, 0, 0);
  if (D_004A12A4 == 17) func_001B4738(9, 2, 30, 0); else func_0029B450(buf); }
