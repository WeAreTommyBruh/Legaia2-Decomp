#include "../common.h"
extern char D_00343028[]; extern int D_00425510[]; extern int D_004A6B40; extern int D_00620058[];
int func_0010C2B0(char *, int, int, int, int, int, int); void func_001B4738(int, int, int, int);
// MATCH func_002B9AF8
int FUN_002b9af8(void) {
  func_0010C2B0(D_00343028, 0x14, 3, 0, 2, 0, 0);
  if ((D_00425510[2] & 0x20) != 0) D_00425510[2] = D_00425510[2] | 1;
   D_004A6B40 |= 8;   D_00620058[1] = 8;  D_00620058[0] = 1;   D_00620058[2] = 0;   D_00620058[5] = 0;  D_00620058[4] = 0;   D_00620058[3] = 0; 
  func_001B4738(1, 1, 1, 0);
  return 1;
}
