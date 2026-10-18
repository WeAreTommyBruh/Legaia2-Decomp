// compiler: 990721-r5900
#include "../src/common.h"
typedef struct { char c[8]; } V8;
typedef struct { int cnt; char p4[20 - 4]; int hp; char p18[28 - 24]; char s0[96 - 28]; char s1[164 - 96]; char s2[232 - 164]; char s3[300 - 232]; char *list; int p130; int n; char p138[412 - 312]; V8 a; } O;
extern float D_004A09B4;
extern char D_004A5A08[], D_004A5A10[];
extern V8 D_004A5A18[2];
void FUN_0025de00(void *, float);
void FUN_0025e508(void *, float);
int DbgPrintf(char *, ...);
// WIP func_25F388
int abeshi_0025f388(O *o)
{
  float f;
  int i;
  if (++o->n < 25) {
    f = (float)((25 - o->n) / 100);
    FUN_0025de00((char *)o + 28, f);
    FUN_0025de00((char *)o + 96, f);
    FUN_0025de00((char *)o + 164, f);
    FUN_0025de00((char *)o + 232, f);
    o->hp -= 16;
    if (o->hp < 0) o->hp = 0;
    {
      float g = D_004A09B4;
      for (i = 0; i < o->cnt; i++)
        FUN_0025e508(o->list + i * 44, (1.0f - f) + g);
    }
    DbgPrintf(D_004A5A08, o->hp);
  } else {
    f = 0.0f;
    FUN_0025de00((char *)o + 28, f);
    FUN_0025de00((char *)o + 96, f);
    FUN_0025de00((char *)o + 164, f);
    FUN_0025de00((char *)o + 232, f);
    o->hp = 0;
    DbgPrintf(D_004A5A10, 0);
    o->a = D_004A5A18[0];
  }
  return 0;
}
