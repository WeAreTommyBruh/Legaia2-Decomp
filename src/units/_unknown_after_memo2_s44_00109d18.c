// compiler: 990721-r5900
#include "../common.h"
typedef struct { unsigned data, addr, size, mode; } D_109D18;
extern int D_00343028[]; extern int D_004A3850, D_004A118C, D_004A12B0; extern char D_0042CDB0[];
void func_001118F8(char *, ...); void func_002DC804(void *, int, int); void func_002E5B20(int); unsigned func_002E5C60(void *, int); int func_002E5C40(unsigned);
// MATCH func_00109D18
int FUN_00109d18(int a, unsigned addr, int size) { char buf[65536]; D_109D18 d[16]; char *p; int i; unsigned end, len, x; D_109D18 *q;
  if (!(D_00343028[0] & 8) && D_004A3850 != 2) {
    if (D_004A118C & 0x40) func_001118F8(D_0042CDB0, D_004A12B0);
    i = 0; func_002DC804(buf, 0, 0x10000); for (p = buf; i < 0x10000; i += 16) { p[0] = 12; p[1] = 2; p += 16; } x = addr; end = x + size; for (i = 0; x < end && i < 16; i++) { len = end - x; if (len > 0x10000) len = 0x10000; d[i].addr = x; d[i].data = (unsigned)buf; d[i].size = len; d[i].mode = 0; x += len; }     func_002E5B20(0);
    { unsigned id = func_002E5C60((void *)d, i); if (id == 0) return -1; while (func_002E5C40(id) >= 0) ; }
  }
  return 1; }
