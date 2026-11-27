#include "../common.h"
typedef struct { char p[20]; int w20; } B_16CDC0;
typedef struct { char p0[16]; B_16CDC0 *w16; int w20; void * w24; int w28; int w32; int w36; int pad40; int w44; int w48; char p52[32]; int w84; int w88; int w92; int w96; int w100; char v104[8]; } O_16CDC0;
typedef struct { char c[8]; } V8_16CDC0;
extern V8_16CDC0 D_004A2FA8[3]; extern V8_16CDC0 D_004A2FB0[3]; extern char D_0043D438[]; extern char D_0043D450[];
int func_001644A0(char *); int func_00153B40(char *); void func_002971C0(); int func_0018B3A8(char *, int); void func_001118F8(char *);
// MATCH func_0016CDC0
O_16CDC0 *FUN_0016cdc0(O_16CDC0 *o, B_16CDC0 *b) {
int t; t = b->w20; o->w20 = (int)t; o->w28 = 0; o->w32 = 0; o->w36 = 0; o->w44 = 0; o->w48 = 0; o->w24 = 0; o->w16 = b;
  func_001644A0((char *)o + 52);
  o->w88 = 0;
  o->w92 = 0;
  o->w84 = 1;
  *(V8_16CDC0 *)o->v104 = D_004A2FA8[0];
  func_00153B40((char *)o + 128);
  func_00153B40((char *)o + 352);
  *(V8_16CDC0 *)((char *)o + 584) = D_004A2FB0[0];
  func_002971C0(0, 0);
  o->w100 = 0;
  o->w96 = func_0018B3A8(D_0043D438, 0);
  if (o->w96 == 0) func_001118F8(D_0043D450);
  return o;
}
