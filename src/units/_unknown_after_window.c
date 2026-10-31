/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_004A3864; void func_001118F8(void *);
// MATCH func_00197E58
void FUN_00197e58(void *a) { if (D_004A3864 & 0x10000) func_001118F8(a); }

int func_002CB958(int *, int); void func_002CC6D8(int);
// MATCH func_00196FA0
int FUN_00196fa0(int a) { int buf[12]; if (func_002CB958(buf, a) == 0) return -1; func_002CC6D8(buf[0]); return buf[0]; }

extern int D_004A3864_001962C0 __asm__("D_004A3864"); extern char D_004A3840[4], D_004A3848[4]; extern int D_00343028_001962C0[] __asm__("D_00343028"); extern char D_00441440[]; void func_001118F8_001962C0(char *, ...) __asm__("func_001118F8"); int func_00196368(void);
// MATCH func_001962C0
void FUN_001962c0(void) { int *p; if (D_004A3864_001962C0 & 1) func_001118F8_001962C0(D_00441440); p = D_00343028_001962C0; p[2] = 2048; p[1] = 64; D_004A3840[0] = 0; D_004A3840[1] = 0; D_004A3840[2] = 0; D_004A3840[3] = 0; D_004A3848[0] = 0; D_004A3848[1] = 0; D_004A3848[2] = 0; D_004A3848[3] = 0; p[4] = 0; p[6] = 0; p[5] = func_00196368(); }

extern char D_005ABD00[], D_005ABB00[], D_00343010_00197DE0[] __asm__("D_00343010"), D_00343028_00197DE0[] __asm__("D_00343028"), D_0043B400[]; extern float D_004A01C0; void func_00153B40_00197DE0(char *) __asm__("func_00153B40"); void func_001E2638(char *); void func_001098B8(char *);
// MATCH func_00197DE0
void FUN_00197de0(void) { int i; char *p; func_00153B40_00197DE0(D_005ABD00); p = D_005ABB00; for (i = 3; i != -1; i--) { *(int *)(p + 52) = (int)D_0043B400; *(float *)(p + 112) = 1.0f; *(int *)(p + 116) = 0; *(int *)(p + 120) = 0; *(float *)(p + 124) = D_004A01C0; p += 128; } func_001E2638(D_00343010_00197DE0); func_001098B8(D_00343028_00197DE0); }
