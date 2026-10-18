// compiler: 990721-r5900
#include "../src/common.h"
extern unsigned D_00425510[4];
extern unsigned D_004A69FC;
extern char D_00424A18[], D_00424A98[];
int FUN_001114b0(void);
int strcmp(char *, char *);
// WIP func_002B0978
void shikimi_002b0978(void)
{
  if (FUN_001114b0() != 0)
    D_00425510[0] |= 0x4000;
  D_00425510[0] |= 1;
  D_00425510[0] &= 0xfffffffdU;
  D_00425510[0] &= 0xfffffffbU;
  D_00425510[0] &= 0xffffffdfU;
  D_00425510[0] &= 0xffffffbfU;
  D_00425510[0] &= 0xffffff7fU;
  D_00425510[0] &= 0xfffffeffU;
  D_00425510[0] &= 0xfffffdffU;
  D_00425510[0] &= 0xfffbffffU;
  D_00425510[0] &= 0xfff7ffffU;
  D_00425510[0] &= 0xffdfffffU;
  D_00425510[0] &= 0xf7ffffffU;
  D_00425510[2] &= 0xfffffffeU;
  D_00425510[2] &= 0xfffffdffU;
  D_00425510[3] &= 0xfffeffffU;
  D_00425510[3] &= 0xfffdffffU;
  D_00425510[3] &= 0xfffbffffU;
  D_00425510[3] &= 0xfff7ffffU;
  D_00425510[3] &= 0xffefffffU;
  D_00425510[3] &= 0xffdfffffU;
  D_00425510[3] &= 0xffbfffffU;
  D_00425510[3] &= 0xff7fffffU;
  D_00425510[3] &= 0xfeffffffU;
  D_00425510[3] &= 0xfdffffffU;
  D_00425510[3] &= 0xfbffffffU;
  D_00425510[3] &= 0xf7ffffffU;
  D_00425510[3] &= 0xffffU;
  if ((D_004A69FC & 0x40) == 0 || strcmp(D_00424A98, D_00424A18) != 0) {
    D_00425510[3] &= 0xfffffffeU;
    D_00425510[3] &= 0xfffffffdU;
    D_00425510[3] &= 0xfffffffbU;
    D_00425510[3] &= 0xfffffff7U;
    D_00425510[3] &= 0xffffffefU;
    D_00425510[3] &= 0xffffffdfU;
    D_00425510[3] &= 0xffffffbfU;
    D_00425510[3] &= 0xffffff7fU;
    D_00425510[3] &= 0xfffffeffU;
    D_00425510[3] &= 0xfffffdffU;
    D_00425510[3] &= 0xfffffbffU;
    D_00425510[3] &= 0xfffff7ffU;
    D_00425510[3] &= 0xffffefffU;
    D_00425510[3] &= 0xffffdfffU;
    D_00425510[3] &= 0xffffbfffU;
    D_00425510[3] &= 0xffff7fffU;
  }
}
