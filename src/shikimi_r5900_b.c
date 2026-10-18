/* More functions of shikimi.cpp (a separate file: FUN_00160c70 is declared differently). */
// compiler: 990721-r5900
#include "common.h"
typedef struct { int f0; char p4[484]; int f1e8, f1ec, f1f0, f1f4; char p1f8[608 - 504]; } Ent608;
extern Ent608 D_005F9640[];
extern int D_004A69A8, D_004A735C;
extern unsigned D_004A6B40;
extern char D_0041EF40[], D_004A6A18[], D_004A6A20[], D_004A6A60[], D_00421420[];
int FUN_00160778(char *, char *);
int FUN_00160c70(char *, char *, int);
void FUN_0029bbd0(int *, int, int);
void FUN_002bee18(int *, int);
void clas_min_002a0538(Ent608 *, char *, int);
void shikimi_002b1010(void);
void shikimi_002b1058(void);
int shikimi_002b3f10(int, Ent608 *, int *);

// MATCH func_002B0DD8
int shikimi_002b0dd8(void)
{
  int n;
  Ent608 *e;
  int v[3];
  switch (D_004A735C) {
  case 0:
    n = FUN_00160778(D_0041EF40, D_004A6A18);
    {
      int i;
      for (i = 3; i < n; i++)
        clas_min_002a0538(&D_005F9640[D_004A69A8], D_00421420, i);
    }
    D_004A735C = 1;
    break;
  case 1:
    shikimi_002b1010();
    if ((D_004A6B40 & 0x1000) == 0)
      shikimi_002b1058();
    {
      int i;
      for (i = 3; i < D_004A69A8; i++) {
        e = &D_005F9640[i];
        if ((e->f1f0 & 2) != 0)
          shikimi_002b3f10(FUN_00160c70(D_0041EF40, D_004A6A18, e->f1e8), e, &e->f1ec);
        if ((e->f1f0 & 4) != 0)
          shikimi_002b3f10(FUN_00160c70(D_0041EF40, D_004A6A20, e->f1e8), e, &e->f1ec);
      }
    }
    D_004A735C = 2;
    break;
  case 2:
    n = FUN_00160778(D_0041EF40, D_004A6A60);
    {
      int i;
      for (i = 0; i < n; i++) {
        v[0] = 1;
        v[1] = 1;
        v[2] = 1;
        FUN_0029bbd0(v, FUN_00160c70(D_0041EF40, D_004A6A60, i), i);
        FUN_002bee18(v, 2);
      }
    }
    D_004A735C = 3;
    break;
  default:
    return 1;
  }
  return 0;
}
