#include "../common.h"
extern char D_00424A98[], D_0049AE40[];
void func_002A2118(void); void func_002A2420(int *); void func_002A3268(int *, int); int func_002A3278(int *); void func_002BEA90(int *, char *); void func_0024ABE0(char *);
// MATCH func_002A2308
void clas_min_002a2308(int *o, int a) {
  if (a != 0) func_002A2118();
  func_002A2420(o);
  o[11] = 0;
  func_002A3268(o, o[0]);
  while (func_002A3278(o) == 0) ;
  func_002BEA90(o, D_00424A98);
  func_0024ABE0(D_0049AE40);
}
