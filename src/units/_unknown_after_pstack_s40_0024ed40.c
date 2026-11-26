#include "../common.h"
typedef struct { char p[6372]; signed char k[3]; } T; extern T D_003FEBA8;
typedef struct { int w0, w4, w8, w12; char p[12]; int w28; char q[40]; } E72; extern E72 D_003FDFA0[];
// MATCH func_0024ED40
int FUN_0024ed40(void) { int r = 0; int i;
  for (i = 0; i < 3; i++) { int c = D_003FEBA8.k[i]; if ((unsigned)c < 5) { E72 *e = &D_003FDFA0[c]; int a = e->w12, b = e->w28;
    if (a & 0x20000000) r |= 0x10; if (a & 0x40000000) r |= 0x20; if (a & 0x80000000) r |= 0x40;
    if (b & 2) r |= 1; if (b & 4) r |= 2; if (b & 8) r |= 4; if (b & 0x10) r |= 8; } }
  if ((r & 0x40) || (r & 0x30) == 0x30) { r &= ~0x10; r &= ~0x20; }
  return r; }
