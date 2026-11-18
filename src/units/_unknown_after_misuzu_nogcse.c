/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { float x, y, z; } V_1F5780;
typedef struct { char p0[140]; V_1F5780 a; char p152[32]; V_1F5780 b; } W_1F5780;
typedef struct { char p0[20]; W_1F5780 *w20; void *w24; } G_1F5780;
typedef struct { int w0; char p4[60]; } T_1F5780;
extern long long D_004A12D8; extern int D_004A4070, D_004A4078, D_004A407C; extern G_1F5780 D_0036CB88[]; extern T_1F5780 D_003BCE20[];
void func_001B7980(float, V_1F5780 *); void func_001AE398(W_1F5780 *); void func_001AD888(W_1F5780 *, int); void func_001AF660(void *, int); void func_001B4B40(int);
int func_001AD830(W_1F5780 *); void func_001AD868(W_1F5780 *, int); void func_001F58C8(W_1F5780 *, int);
#define vz_1F5780(V_) { V_1F5780 *v_ = (V_); func_001B7980(v_->z, v_); }
#define close_1F5780() { vz_1F5780(&D_0036CB88[0].w20->a); vz_1F5780(&D_0036CB88[0].w20->b); func_001AE398(D_0036CB88[0].w20); func_001AD888(D_0036CB88[0].w20, 20); func_001AF660(D_0036CB88[0].w24, 0); func_001B4B40(D_004A4070); }
// MATCH func_001F5780
void FUN_001f5780(void) {
  if (D_004A12D8 & 0x10) close_1F5780()
  if (!(D_004A12D8 & 0x40)) return;
  if (func_001AD830(D_0036CB88[0].w20) < 99) { func_001AD868(D_0036CB88[0].w20, 99); return; }
  if (D_003BCE20[++D_004A4078].w0 != D_004A407C) { close_1F5780() return; }
  func_001F58C8(D_0036CB88[0].w20, D_004A4078);
}
