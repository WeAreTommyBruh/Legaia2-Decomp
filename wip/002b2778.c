#include "../src/common.h"
typedef struct { int p0; short f4, p6, f8, p0a, fc, p0e, f10, p12; int f14, f18, f1c; unsigned short f20, p22; int f24, f28, f2c; unsigned short f30, p32; } Dsc2778;
typedef struct { char p0[0x18]; int f18; char p1c[0xb4 - 0x1c]; short fb4, fb6; int fb8; short fbc, fbe; char pc0[0xcc - 0xc0]; short fcc, fce; char pd0[0x178 - 0xd0]; short f178, f17a; char p17c[0x18c - 0x17c]; int f18c, f190, f194, f198; } Ef2778;
extern int D_002F9804[];
extern char D_004213D0[], D_0049AC68[];
Ef2778 *work_00246d88(char *, int);
int DbgPrintf();
// WIP func_002B2778
int shikimi_002b2778(Dsc2778 *d, int a)
{
  Ef2778 *e = work_00246d88(D_004213D0, D_002F9804[0]);
  if (e != 0) {
    // PERM-BEGIN
    e->fb4 = 0;
    e->fb6 = d->f30;
    e->f178 = 0;
    e->f17a = d->f20;
    e->fcc = d->f4;
    e->fce = d->f8;
    e->fbc = d->fc;
    e->f18c = d->f24;
    e->fbe = d->f10;
    e->f190 = d->f28;
    e->fb8 = -1;
    e->f198 = d->f2c;
    e->f18 = a;
    // PERM-END
    switch (d->f1c) {
    case 0:
    case 3:
      e->f194 = d->f14 != 0;
      if (d->f1c == 3) e->fb8 = d->f18;
      return 3;
    case 1:
      return e->f194 = 1;
    case 2:
    case 9:
      if (d->f1c == 9) e->fb8 = d->f18;
      return e->f194 = 2;
    case 4:
      return e->f194 = 3;
    case 5:
      return e->f194 = 4;
    case 6:
      return e->f194 = 6;
    case 7:
      return e->f194 = 8;
    case 8:
      return e->f194 = 9;
    }
    return 0;
  }
  DbgPrintf(D_0049AC68);
}
