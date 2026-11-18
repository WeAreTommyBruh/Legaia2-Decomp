/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern float D_004A0680; void func_00235138(float);
// MATCH func_00235130
void FUN_00235130(void) { func_00235138(D_004A0680); }

extern float D_004A0670; extern int D_004A14B8_00231E30 __asm__("D_004A14B8"); void func_0018E860(float *, float, float, float); void func_0018F3D8_00231E30(float *, float *, float *) __asm__("func_0018F3D8"); void func_0018DF68_00231E30(float *, float *) __asm__("func_0018DF68");
// MATCH func_00231E30
void FUN_00231e30(int a, int b, int c) { func_0018E860((float *)0x70003f00, a * D_004A0670, b * D_004A0670, c * D_004A0670); func_0018F3D8_00231E30((float *)0x70003f80, (float *)0x70003f80, (float *)0x70003f00); func_0018F3D8_00231E30((float *)0x70003c80, (float *)0x70003c80, (float *)0x70003f00); if (D_004A14B8_00231E30 != 0) { func_0018DF68_00231E30((float *)0x70003f40, (float *)0x70003f00); func_0018F3D8_00231E30((float *)0x70003d80, (float *)0x70003f40, (float *)0x70003d80); } }

void func_00235338(float, float, float, float, int, int, int, int, int, int, int, int, int, int, int);
// MATCH func_00235680
void FUN_00235680(float a, float b, int i0, int i1, int i2, int i3, int i4, int i5, int i6, int i7, int i8, int i9, int i10) { func_00235338(a, b, 1.0f, 1.0f, i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }

int func_002302B0_230188(int, int, int, int) __asm__("func_002302B0");
int func_00231580_230188(float, float, int, int, int) __asm__("func_00231580");
int func_0022FDD8_230188(void *) __asm__("func_0022FDD8");
int func_002306E8_230188(int, int, int, int) __asm__("func_002306E8");
int func_00231548_230188(void) __asm__("func_00231548");
// MATCH func_00230188
int FUN_00230188(int p, int i, int c, int d) { char *new_var2; int h; float *new_var; func_002302B0_230188(p, i, c, d); new_var2 = (*((char **) (((char *) p) + 0x90))) + 2052; h = *((int *) (new_var2 + (i * 4))); if (h != 0) { func_00231580_230188(*(new_var = &(*((float *) (((char *) p) + 0x13c)))), *((float *) (((char *) p) + 0x140)), p, h, (int) (*((float *) (((char *) p) - -0x144)))); } func_0022FDD8_230188((void *) p); func_002306E8_230188(p, i, c, d); func_00231548_230188(); }


typedef struct { char p0[232]; short a[8]; short b[8]; char p264[16]; float f[8]; } O_230B78;
extern int D_004A70E4, D_004A70A8;
int func_0022F960(float, float, O_230B78 *, unsigned short *, int, short *, int); void func_0017FC20(unsigned short *, int);
// MATCH func_00230B78
unsigned FUN_00230b78(O_230B78 *o, int u, unsigned short *k) {
  unsigned r; int i;
  if (D_004A70E4 == 2) return 0;
  r = *k;
  if (((r ^ 1) & 1) && (r & 2)) {
    D_004A70A8 = 0;
    r &= 0xfeff;
    for (i = 0; i < 8; i++) {
      if (o->b[i] >= 0 && func_0022F960(o->f[i], 1.0f, o, k, i, &o->a[i], o->b[i])) r |= 0x100;
    }
  }
  if (r & 0x100) {
    if (r & 1) func_0017FC20(k, 1);
    else func_0017FC20(k, 2);
  }
  return r;
}

typedef struct { char p[720]; float v[4]; } SP_235C48;
void func_0018F3D8(int, int, int); void func_00249880(int *, int, int); void func_0018EC58(int); void func_0018F620(int, int);
// MATCH func_00235C48
int FUN_00235c48(float *ox, float *oy, int *p, int q, float x, float y) {
  int r[4];
  ((SP_235C48 *)0x70003b70)->v[3] = 1.0f;
  ((SP_235C48 *)0x70003b70)->v[0] = x;
  ((SP_235C48 *)0x70003b70)->v[1] = y;
  ((SP_235C48 *)0x70003b70)->v[2] = 0.0f;
  func_0018F3D8(0x70003f40, 0x70003c00, 0x70003f80);
  func_0018F3D8(0x70003f00, 0x70003bc0, 0x70003f40);
  func_00249880(p, 0x70003f00, q);
  func_0018EC58(0x70003f00);
  func_0018F620(0x70003f00, 0x70003e40);
  func_0018F3D8(0x70003f40, 0x70003f00, 0x70003f40);
  func_0018F3D8(0x70003f00, 0x70003bc0, 0x70003f40);
  func_00249880(r, 0x70003f00, q);
  *ox = r[0] - p[0];
  *oy = r[1] - p[1];
  return p[2];
}
