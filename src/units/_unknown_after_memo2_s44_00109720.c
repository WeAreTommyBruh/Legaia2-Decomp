// compiler: 990721-r5900
#include "../common.h"
typedef struct { unsigned data, addr, size, mode; } D_109720;
extern int D_004A118C, D_004A12B0; extern char D_0042CBD0[], D_0042CBE8[], D_0042CC20[], D_0042CC58[], D_0042CC98[], D_0042CCB8[], D_0042CCD8[];
void func_001118F8(char *, ...); void func_002E5B20(int); unsigned func_002E5C60(void *, int); int func_002E5C40(unsigned); void func_002E5C80(void);
// MATCH func_00109720
unsigned Ee2Iop(unsigned src, unsigned dst, unsigned size, int wait) { D_109720 d; unsigned id;
  if (D_004A118C & 0x40) func_001118F8(D_0042CBD0, D_004A12B0);
  if (D_004A118C & 1) func_001118F8(D_0042CBE8, src, dst, size, (size + 0x3ff) >> 10, src & 0xf, dst & 3, size & 0xf);
  if (dst > 0x200000 || dst + size > 0x200000) func_001118F8(D_0042CC20);
  if ((src & 0xf) || (dst & 3) || (size & 0xf)) func_001118F8(D_0042CC58);
  d.data = src; d.addr = dst; d.size = size; d.mode = 0;
  func_002E5B20(0);
  id = func_002E5C60(&d, 1);
  if (id == 0) { if (D_004A118C & 1) func_001118F8(D_0042CC98); func_002E5C80(); return 0; }
  if (wait == 0) { if (D_004A118C & 1) func_001118F8(D_0042CCB8); while (func_002E5C40(id) >= 0) ; }
  if (D_004A118C & 1) func_001118F8(D_0042CCD8, id);
  return id; }