// cflags: -fno-gcse
#include "../common.h"
typedef struct { char p0[496]; unsigned fl; char p500[8]; float f508; } O_29C410;
extern float D_004A698C, D_004A0D18; extern char D_0041EF80[];
int func_0015A8A8(float, float, char *, int);
// MATCH func_0029C410
void clas_min_0029c410(O_29C410 **pp, int **q) {
  float v = (*pp)->f508;
  if (D_004A698C == v) return;
  if (v < D_004A698C) { D_004A698C = v; return; }
  D_004A698C += 240.0f;
  if (func_0015A8A8(D_004A698C, D_004A0D18, D_0041EF80, **q + 32) == 1) D_004A698C -= 240.0f; else D_004A698C -= 160.0f;
  (*pp)->fl |= 0x100000;
  if ((*pp)->f508 <= D_004A698C) {
    D_004A698C = (*pp)->f508;
    (*pp)->fl &= ~0x100000;
  }
}
