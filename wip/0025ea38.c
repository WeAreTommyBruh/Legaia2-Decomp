// compiler: 990721-r5900
#include "../src/common.h"
typedef struct { char c[8]; } V8;
extern V8 D_004A59E0[2];
extern char D_00489038[], D_00489048[], D_00402438[];
extern float D_004A0994, D_004A0998, D_004A099C;
void FUN_0025dd78(void *, int, int);
void FUN_0025dde8(void *, int, int, int, int);
void FUN_0025de00(void *, float);
void FUN_0025de20(float, void *, int);
void FUN_0025e3f8(void *);
void FUN_002971c0(int, int);
void FUN_00202840(void *);
void minigame_001644a0(void *);
void abeshi_0025ee38(void *);
void *MemAllocDbg(int, char *, int);
void *MallocLoadFileNB(char *, int);
int DbgPrintf(char *, ...);
// WIP func_25EA38
int *abeshi_0025ea38(int *o, int n)
{
  int *a, *b, *c, *d, *m, *r, *s;
  int k;
  void *t;
  a = o + 7;
  b = o + 0x29;
  c = o + 0x18;
  d = o + 0x3a;
  o[0] = n;
  k = n - 1;
  o[1] = n;
  o[2] = 0;
  o[3] = 0;
  o[4] = 0;
  o[5] = 0;
  o[6] = 1;
  FUN_0025dd78(a, 0x10, 0);
  FUN_0025dd78(c, 0x40, 2);
  FUN_0025dd78(b, 0x80, 1);
  FUN_0025dd78(d, 0x20, 3);
  o[0x4d] = 0;
  minigame_001644a0(o + 0x4f);
  o[0x51] = 0;
  o[0x52] = 0;
  FUN_00202840(o + 0x54);
  *(V8 *)(o + 0x67) = D_004A59E0[0];
  FUN_002971c0(0, 0);
  FUN_0025dde8(a, 0x140, -0x20, 0x140, 0x39);
  FUN_0025dde8(c, 0x140, 0x100, 0x140, 0xa7);
  FUN_0025dde8(b, -0x40, 0x70, 0xd1, 0x70);
  FUN_0025dde8(d, 0x2c0, 0x70, 0x1af, 0x70);
  FUN_0025de00(a, 0.0f);
  FUN_0025de00(c, 0.0f);
  FUN_0025de00(b, 0.0f);
  FUN_0025de00(d, 0.0f);
  FUN_0025de20(D_004A0994, a, 0x4000);
  FUN_0025de20(D_004A0998, c, 0x400000);
  FUN_0025de20(D_004A099C, b, 0x202040);
  FUN_0025de20(0.0f, d, 0x40);
  r = MemAllocDbg(n * 0x2c + 0x10, D_00489038, 520);
  *r = n;
  s = r + 4;
  m = s;
  if (n != 0) {
    do {
      k--;
      FUN_0025e3f8(m);
      m += 11;
    } while (k != -1);
  }
  o[0x4b] = (int)s;
  o[0x4c] = 0;
  abeshi_0025ee38(o);
  o[0x66] = 0;
  t = MallocLoadFileNB(D_00402438, 0);
  o[0x53] = (int)t;
  if (t == 0) DbgPrintf(D_00489048);
  return o;
}
