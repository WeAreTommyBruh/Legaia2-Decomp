// compiler: 990721-r5900
#include "../src/common.h"
typedef struct { int p0, f4, f8, fc, f10, f14, f18, f1c; } Op8ee8;
extern char D_0049B978[];
extern long long D_0049ACD0[2], D_00421260[2];
extern char D_00343028[];
extern float D_0061FF60[], D_0061FF78[];
extern int D_004A689C, D_004A68A0, D_004A67B4, D_004A72D4, D_004A72D8;
extern unsigned D_004A6B40;
char *MemAllocDbg(int, char *, int);
void MemFreeDbg(char *, char *, int);
void shikimi_002b8de0(char *, char *);
void shikimi_002b2738(int, int, int, int);
void clas_min_0029d010(float, float *, int, int);
long FUN_0010d7e8(char *, int, char *);
int FUN_0010d8a0(char *, char *);
int FUN_0010e1a0(char *, int);
void FUN_0010e368(char *);
int *FUN_0010e938(char *, int);
int strcmp(char *, char *);
char *strcpy(char *, char *);
void *memcpy(void *, const void *, unsigned);
// WIP func_002B8EE8
void shikimi_002b8ee8(Op8ee8 *o, char *a)
{
  char *b;
  int v;
  long r;
  b = MemAllocDbg(0x100, D_0049B978, 3786);
  if (D_004A689C != 0) {
    switch (o->f8) {
    case 0:
    case 4:
      shikimi_002b8de0(b, a);
      if (strcmp((char *)D_00421260, b) != 0) {
        D_004A67B4 = o->fc;
        strcpy((char *)D_00421260, b);
        D_004A6B40 &= 0xffffbfff;
        FUN_0010e368(D_00343028);
        if (o->f8 == 0) {
          D_004A72D8 = D_004A72D4 = D_004A68A0;
          shikimi_002b2738(7, 0, 0, 0);
        } else if (o->f8 == 4) {
          do {
            r = FUN_0010d7e8(D_00343028, o->fc, b);
          } while (r == -3);
          D_0061FF60[0] = D_0061FF78[0] = 0.0f;
          clas_min_0029d010((float)D_004A68A0, D_0061FF78, 0, 10);
          clas_min_0029d010((float)D_004A68A0, D_0061FF60, 0, 10);
          FUN_0010e1a0(D_00343028, 0);
        }
      } else {
        clas_min_0029d010((float)D_004A68A0, D_0061FF78, 0, 10);
        clas_min_0029d010((float)D_004A68A0, D_0061FF60, 0, 10);
      }
      break;
    case 1:
      memcpy(D_00421260, D_0049ACD0, 9);
      D_004A67B4 = 0;
      clas_min_0029d010(0.0f, D_0061FF78, 0, 10);
      clas_min_0029d010(0.0f, D_0061FF60, 0, 10);
      break;
    case 5:
      memcpy(D_00421260, D_0049ACD0, 9);
      D_004A6B40 |= 0x4000;
      D_004A67B4 = 0;
      D_004A72D4 = 0;
      D_004A72D8 = 0;
      FUN_0010e368(D_00343028);
      break;
    case 2:
      D_004A72D4 = o->f10;
      D_004A72D8 = o->f14;
      if (D_004A72D4 < 2) D_004A72D4 = 0;
      if (D_004A72D8 < 2) D_004A72D8 = 0;
      clas_min_0029d010((float)D_004A72D4, D_0061FF78, 0, o->f18);
      clas_min_0029d010((float)D_004A72D8, D_0061FF60, 0, o->f1c);
      break;
    case 3:
      memcpy(D_00421260, D_0049ACD0, 9);
      D_004A67B4 = 0;
      FUN_0010e938(D_00343028, 0);
      if (FUN_0010d8a0(D_00343028, a) != -1)
        shikimi_002b2738(8, 0, 0, 0);
      break;
    }
  }
  MemFreeDbg(b, D_0049B978, 3863);
}
