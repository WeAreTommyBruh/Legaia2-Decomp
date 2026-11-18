/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
#include "../common.h"

typedef struct { char p0[24]; int f24; int f28; int f32; int f36; int f40; float f44; char p48[16]; float f64; float f68; float f72; char p76[20]; float f96; float f100; float f104; char p108[4]; float f112; float f116; float f120; float f124; char p128[20]; int f148; int f152; char p156[4]; int f160; char p164[4]; int f168; char p172[4]; int f176; char p180[4]; int f184; short f188; short f190; int f192; float f196; float f200; short f204; short f206; signed char f208; unsigned char f209; unsigned char f210; char f211; int f212; char p216[4]; int f220; float f224; short f228; short f230; short af232[8]; short af248[8]; char af264[8]; char af272[8]; int af280[8]; int af312[8]; float af344[8]; short f376; short f378; float f380; int f384; int f388; short f392; } W_2461E0;
extern int D_004A7204, D_00320880[]; extern float D_004A0808;
void func_00246800(W_2461E0 *);
// MATCH func_002461E0
void work_002461e0(W_2461E0 *w) {
  int i;
  w->f28 = D_004A7204;
  w->f209 = 128;
  w->f392 = 0;
  w->f176 = 0;
  w->f24 = 0;
  for (i = 0; i < 8; i++) {
    w->af312[i] = 0;
    w->af280[i] = 0;
    w->af248[i] = -1;
    w->af264[i] = -1;
    w->af272[i] = -1;
    w->af232[i] = 0;
    w->af344[i] = -1.0f;
  }
  w->f124 = 0;
  w->f210 = 128;
  w->f208 = -1;
  w->f160 = (int)D_00320880;
  *(float *)&w->af312[6] = 1.0f;
  w->f112 = 1.0f;
  w->f116 = 1.0f;
  w->f120 = 1.0f;
  w->f44 = 1.0f;
  w->f200 = 1.0f;
  w->f230 = -1;
  w->f190 = -2;
  w->f72 = w->f124;
  w->f68 = w->f124;
  w->f64 = w->f124;
  w->f196 = w->f124;
  w->f380 = w->f124;
  w->f384 = 0;
  w->f388 = 0;
  w->f148 = 0;
  w->f211 = 0;
  w->f32 = 0;
  w->f36 = 0;
  w->f40 = 0;
  w->f220 = 0;
  w->f192 = 0;
  w->f204 = 0;
  w->f206 = 0;
  w->f168 = 0;
  w->f188 = 0;
  w->f228 = 0;
  w->f184 = 0;
  w->f152 = 0;
  w->f376 = 0;
  w->f378 = 0;
  w->f96 = w->f124;
  w->f100 = w->f124;
  w->f104 = w->f124;
  w->f212 = 0x808080;
  func_00246800(w);
  w->f224 = D_004A0808;
}
