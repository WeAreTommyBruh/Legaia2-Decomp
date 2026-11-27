// compiler: 990721-r5900
#include "../common.h"
typedef struct { long f; char p[8]; unsigned char c[4]; char q[348]; } E_24AD58;
extern E_24AD58 D_003187C0[];
// MATCH func_0024AD58
void init_0024ad58(int a, int b, int c, int d) {
  if (d != 0x80) { D_003187C0[1].f |= 0x40; D_003187C0[2].f |= 0x40; } else { D_003187C0[1].f &= ~0x40L; D_003187C0[2].f &= ~0x40L; }
  D_003187C0[1].c[0] = a; D_003187C0[1].c[1] = b; D_003187C0[1].c[2] = c; D_003187C0[1].c[3] = d; D_003187C0[2].c[0] = a; D_003187C0[2].c[1] = b; D_003187C0[2].c[2] = c; D_003187C0[2].c[3] = d;
}
