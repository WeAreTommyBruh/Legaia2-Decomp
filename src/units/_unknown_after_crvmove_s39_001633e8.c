#include "../common.h"
typedef unsigned long U64;
typedef struct { char pad[16]; U64 *p; } PK_1633E8;
extern PK_1633E8 D_00314C20;
extern int D_00319660[];
// MATCH func_001633E8
void FUN_001633e8(int x, int y, short *r) {
  U64 *p;
  int s0, s1, s2, s3;
  U64 t, q6, q2;
  t = (long)(D_00319660[r[4]] + 0x3140) | 0x6a9300000UL | ((long)(r[5] * 4 + 0x3c00) << 37) | 0x20000 | 0x2000000000000000UL;
  p = D_00314C20.p;
  p[1] = 6;
  p[0] = t;
s3 = r[3]; s2 = r[2]; s0 = r[0]; s1 = r[1]; x += 0x6c0; q2 = (long)s0 << 4 | (long)s1 << 20; q6 = (long)s2 << 4 | (long)s3 << 20; { register U64 *np __asm__("$3") = p + 10; D_00314C20.p = np; } y += 0x790; p[4] = (long)(x * 16) | (long)(y * 16) << 16 | 0xfffff000000000UL; p[3] = 3; p[5] = 12; p[6] = q6; p[7] = 3; p[8] = (long)((x + (s2 - s0)) * 16) | (long)((y + (s3 - s1) / 2) * 16) << 16 | 0xfffff000000000UL; p[9] = 4; p[2] = q2;
}
