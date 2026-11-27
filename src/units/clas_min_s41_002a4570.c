#include "../common.h"
extern int D_004A72F8;
extern char D_00321060[], D_0041EF40[], D_004A6850[];
char *func_00160C70(char *, char *, int);
char *func_002DD4CC(char *, char *);
void func_002DD718(char *);
// MATCH func_002A4570
void clas_min_002a4570(int a, int b) {
  D_004A72F8 = b;
  func_002DD4CC(D_00321060, func_00160C70(D_0041EF40, D_004A6850, b));
  func_002DD718(D_00321060);
}
