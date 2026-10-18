// compiler: 990721-r5900
#include "../src/common.h"
extern char D_00343010[], D_00489038[];
void FUN_002971c0(int, int);
void FUN_001e3f20(char *, int);
void FUN_0025e448(char *, int);
void FUN_00131588(char *);
void MemFreeDbg(void *, char *, int);
void eftpack_00202878(char *, int);
void FUN_00164500(char *, int);
void FUN_0025ddc8(char *, int);
void FUN_00108b80(char *);
// WIP func_25ECA8
void abeshi_0025eca8(char *o, u64 flags)
{
  int *q = (int *)(o + 0x174);
  int n = 8;
  int v;
  char *a, *e;
  FUN_002971c0(0x12, 0x32);
  v = *q;
  while (1) {
    q++;
    n--;
    FUN_001e3f20(D_00343010, v);
    if (n < 0) break;
    v = *q;
  }
  a = *(char **)(o + 300);
  if (a != 0) {
    e = a + *(int *)(a - 0x10) * 0x2c;
    if (a == e) {
      a = *(char **)(o + 300);
    } else {
      do {
        e -= 0x2c;
        FUN_0025e448(e, 0);
      } while (*(char **)(o + 300) != e);
      a = *(char **)(o + 300);
    }
    FUN_00131588(a - 0x10);
  }
  MemFreeDbg(*(void **)(o + 0x14c), D_00489038, 0x221);
  eftpack_00202878(o + 0x150, 2);
  FUN_00164500(o + 0x13c, 2);
  FUN_0025ddc8(o + 0xe8, 2);
  FUN_0025ddc8(o + 0xa4, 2);
  FUN_0025ddc8(o + 0x60, 2);
  FUN_0025ddc8(o + 0x1c, 2);
  if ((flags & 1) == 0) return;
  FUN_00108b80(o);
}
