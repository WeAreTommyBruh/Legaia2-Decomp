// cflags: -fno-thread-jumps
// compiler: 990721-r5900
#include "../src/common.h"
extern int D_004A724C, D_004A7250, D_004A7254, D_004A7258;
extern int D_004A5E38, D_004A5E3C, D_004A5E40, D_004A5E44;
extern int D_005F8780[21];
extern u64 D_0048CEA8[], D_0048CEC0[], D_0048CED0[];
extern char D_0048CEE8[], D_004A5E48[], D_00343028[];
extern int *D_004042C0[];
int FUN_002cbb80(int);
void FUN_0023c728(char *, int);
char *strcat(char *, const char *);
int FUN_0010d8a0(void *, char *);
int DbgPrintf(char *, ...);
typedef struct { char pad[24]; u32 flags; char p2[184 - 28]; int state; } Obj;
// WIP func_00260428
void FUN_00260428(Obj *o)
{
  char buf[64];
  int r;
  if ((u32)D_004A724C > 20) {
    o->flags |= 8;
    return;
  }
  if (D_004A7250 < 0 || D_005F8780[D_004A724C] < D_004A7250) {
    o->flags |= 8;
    return;
  }
  switch (o->state) {
  case 0:
    D_004A5E44 = 1;
    switch (D_004A724C) {
    case 6:
      if (D_004A7250 >= 268 || D_004A7250 == 2 || D_004A7250 == 4) {
        __builtin_memcpy(buf, D_0048CEA8, 18);
        break;
      }
    case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
      __builtin_memcpy(buf, D_0048CEC0, 15);
      break;
    default:
      __builtin_memcpy(buf, D_0048CED0, 18);
      break;
    }
    FUN_0023c728(buf, D_004042C0[D_004A724C][D_004A7250]);
    strcat(buf, D_004A5E48);
    r = FUN_0010d8a0(D_00343028, buf);
    if (r == -1) {
      D_004A5E44 = 0;
      o->flags |= 8;
      D_004A5E38 = -1;
    }
    if (r < 0)
      return;
    DbgPrintf(D_0048CEE8, buf);
    D_004A7254 = -1;
    D_004A7258 = -1;
    o->state++;
    D_004A5E3C++;
    D_004A5E40++;
    if (D_004A5E40 >= 601) {
      D_004A5E44 = 0;
      D_004A7254 = -1;
      D_004A7258 = -1;
      o->flags |= 8;
      D_004A5E38 = -1;
    }
    break;
  case 1:
    D_004A5E3C++;
    if (FUN_002cbb80(1) == 0) {
      u32 f = o->flags;
      D_004A5E44 = 2;
      o->flags = f | 8;
    }
    break;
  }
}
