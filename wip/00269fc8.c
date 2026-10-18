// compiler: 990721-r5900
// cflags: -fno-thread-jumps -fno-cse-skip-blocks
#include "../src/common.h"
typedef struct {
  char unk0[0x78];
  int x78, x7c, x80, x84;
  char unk88[0x94 - 0x88];
  u32 x94, x98;
  char unk9c[0xf0 - 0x9c];
  int xf0;
  char unkf4[0x1ab - 0xf4];
  u8 b1ab;
  char unk1ac[0x1d8 - 0x1ac];
} Rec;
extern struct {
  int money;
  char unk4[0x8c - 4];
  int x8c;
  char unk90[0x18f0 - 0x90];
  Rec rec[5];
} D_003FEBA8;
typedef struct { char p0[0x12d0]; int flags; char p1[0x1560 - 0x12d4]; } Chr;
extern Chr *D_004A1A20;
extern int D_00314D08[4];
extern int D_004A12A4;
extern int D_004A657C, D_004A6580, D_004A6584;
void FUN_00265db0(int);
void FUN_00290bd8(int);
// WIP func_00269FC8
void FUN_00269fc8(int mode)
{
  int saved[7];
  int a, b, c, i;
  switch (mode) {
  case 2:
    a = 1500;
    b = 2000;
    break;
  case 3:
    a = 9000;
    b = 12000;
    break;
  case 4:
    if (D_003FEBA8.rec[0].b1ab == 0)
      D_003FEBA8.rec[0].b1ab = 1;
    a = 24000;
    b = 32000;
    break;
  case 5:
    if (D_003FEBA8.rec[0].b1ab == 0)
      D_003FEBA8.rec[0].b1ab = 1;
    D_003FEBA8.rec[1].xf0 = 0;
    if (D_004A12A4 == 11) {
      for (i = 0; i < 3; i++) {
        if (D_00314D08[i] == 1)
          D_004A1A20[i].flags |= 0x4000;
      }
    }
    a = 90000;
    b = 120000;
    break;
  case 6:
    if (D_003FEBA8.rec[0].b1ab == 0)
      D_003FEBA8.rec[0].b1ab = 1;
    D_003FEBA8.rec[1].xf0 = 0;
    if (D_004A12A4 == 11) {
      for (i = 0; i < 3; i++) {
        if (D_00314D08[i] == 1)
          D_004A1A20[i].flags |= 0x4000;
      }
    }
    a = 300000;
    b = 400000;
    break;
  default:
    a = 0;
    b = 0;
    break;
  }
  c = a;
  saved[0] = D_00314D08[0];
  saved[1] = D_00314D08[1];
  saved[2] = D_00314D08[2];
  saved[3] = D_00314D08[3];
  saved[4] = D_004A657C;
  saved[5] = D_004A6584;
  saved[6] = D_004A6580;
  D_00314D08[3] = -1;
  D_00314D08[2] = -1;
  D_00314D08[1] = -1;
  for (i = 0; i < 5; i++) {
    D_00314D08[0] = i;
    if (D_003FEBA8.rec[i].x94 < a)
      D_004A657C = a - D_003FEBA8.rec[i].x94;
    if (D_003FEBA8.money < b)
      D_004A6584 = b - D_003FEBA8.money;
    if (D_003FEBA8.rec[i].x98 < c >> 1)
      D_004A6580 = (c >> 1) - D_003FEBA8.rec[i].x98;
    FUN_00265db0(1);
  }
  D_00314D08[0] = saved[0];
  D_00314D08[1] = saved[1];
  D_00314D08[2] = saved[2];
  D_00314D08[3] = saved[3];
  D_004A657C = saved[4];
  D_004A6584 = saved[5];
  D_004A6580 = saved[6];
  for (i = 0; i < 4; i++) {
    if (D_00314D08[i] >= 0)
      FUN_00290bd8(i);
  }
}
