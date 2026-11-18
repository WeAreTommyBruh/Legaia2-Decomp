/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { float m[4][4]; } M_2491D8;
extern int D_004A565C, D_004A5658, D_004A14B8; extern char D_0045D790[]; extern signed char D_003DC570[]; extern M_2491D8 D_003DA170[];
void func_001118F8(char *, ...); void func_0018EB98(int, M_2491D8 *);
// MATCH func_002491D8
void FUN_002491d8(void) {
  if (D_004A565C < 0) { func_001118F8(D_0045D790); D_004A565C = 0; D_004A5658 = 0; }
  if ((D_004A14B8 = D_003DC570[--D_004A5658]) != 0) func_0018EB98(0x70003d80, &D_003DA170[--D_004A565C]);
  func_0018EB98(0x70003c80, &D_003DA170[--D_004A565C]);
  func_0018EB98(0x70003f80, &D_003DA170[--D_004A565C]);
}
