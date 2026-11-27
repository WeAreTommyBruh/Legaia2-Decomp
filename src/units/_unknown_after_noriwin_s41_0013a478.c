#include "../common.h"
typedef struct { float x, y, z, w; } V_13A478;
typedef struct { char p0[16]; int w16, w20, w24; } X_13A478;
typedef struct { char p0[168]; X_13A478 *x; char p172[20]; unsigned fl; } O_13A478;
typedef struct { char p0[20]; short h20, h22; char p24[10]; unsigned char b34; } E_13A478;
extern O_13A478 *D_004A2360; extern float D_004A236C; extern int D_004A2378, D_004A2390, D_004A663C, D_004A6640; extern int D_00402470[];
extern float D_0032A4B0[], D_0041EA40[];
void func_0013C220(void); void func_0013A840(void); void func_00133BE0(void); void func_0013A9E0(void); void func_0013ABD8(float);
void func_0013B110(V_13A478 *, O_13A478 *, int, int); void func_0013B758(float); void func_0013B860(float); void func_0013B968(float);
void func_0013BBD8(void); void func_0013BF68(void); void func_0013C9B0(void);
// MATCH func_0013A478
void FUN_0013a478(void) {
  V_13A478 a, t; char *b; E_13A478 *e;
  if (D_004A2360->fl & 0x80) {
    X_13A478 *x = D_004A2360->x;
    D_004A2360->fl &= ~0x80;
    x->w24 = 0;
    x->w20 = 0;
    x->w16 = 0;
    func_0013C220();
  }
  func_0013A840();
  func_00133BE0();
  func_0013A9E0();
  func_0013ABD8(D_004A236C);
  b = (char *)D_004A2360->x + 320;
  func_0013B110(&t, D_004A2360, D_004A2378, D_00402470[(*(E_13A478 **)(b + (D_004A2390 << 2)))->b34]);
  a = t;
  func_0013B758(a.x);
  func_0013B860(a.y);
  func_0013B968(a.z);
  func_0013BBD8();
  func_0013BF68();
  func_0013C9B0();
  b += D_004A2390 * 4; e = *(E_13A478 **)b;
  D_004A663C = e->h20;
  D_004A6640 = e->h22;
  D_0041EA40[0] = D_0032A4B0[3];
  D_0041EA40[1] = D_0032A4B0[4];
  D_0041EA40[2] = D_0032A4B0[1];
  D_0041EA40[3] = D_0032A4B0[2];
}
