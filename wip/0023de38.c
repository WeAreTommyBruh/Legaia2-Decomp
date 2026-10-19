#include "../src/common.h"

typedef struct { long long a, b; } V;
extern V D_0045CE20;
extern int D_004A5580;
extern char D_005F7560[];
int FUN_00230cb0(int, int);
void FUN_00249108(void);
void FUN_0022d470(void *, int, V *);
void FUN_0018f3d8(void *, char *, int);
int FUN_002491d8(void);
// WIP func_23DE38
int yokota_0023de38(int a, int idx)
{
  int ret;
  int s0[16];
  char s1[16];
  V v;
  char *p;
  int o;
  FUN_00230cb0(a, idx);
  ret = 0;
  if (D_004A5580 != 0) {
    FUN_00249108();
    v = D_0045CE20;
    FUN_0022d470(s1, 0x70003f80, &v);
    FUN_0018f3d8(s0, D_005F7560, 0x70003f80);
    s0[12] = 0; s0[14] = 0; s0[13] = 0;
    FUN_0022d470((char *)D_004A5580 + idx * 16, (int)s0, &v);
    ret = FUN_002491d8();
  }
  return ret;
}
