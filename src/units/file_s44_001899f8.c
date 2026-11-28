// cflags: -fno-gcse
#include "../common.h"
typedef struct { int n; int w4; char *buf; int nsec; int nblk; int w20; int *tbl; } F_99F8;
extern unsigned D_004A6F58; extern int D_004A6F54, D_004A6F64; extern char D_004400F8[], D_00440108[], D_00440120[];
void func_001118F8(char *, ...); void *func_00162130(int, char *, int); void func_00196340(int); int func_002C1188(void *); void func_001899D8(void);
// MATCH func_001899F8
F_99F8 *file_001899f8(F_99F8 *f, int n, int a, int mode) { int i; int *p;
  f->w20 = 0; f->n = n; f->w4 = a; f->nsec = D_004A6F58 >> 11;
  func_001118F8(D_004400F8);
  func_001118F8(D_00440108, D_004A6F54, f->nsec);
  f->buf = func_00162130(n << 11, D_00440120, 214);
  f->nblk = f->nsec / n + 1;
  p = func_00162130(f->nblk * 4, D_00440120, 216);
  f->tbl = p;
  for (i = 0; i < f->nblk; i++) *p++ = 0;
  if (mode == 1) func_00196340(1);
  if (mode == 2) func_00196340(0);
  D_004A6F64 = func_002C1188(func_001899D8);
  return f; }
