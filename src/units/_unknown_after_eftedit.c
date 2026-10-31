/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { int a0, a4, a8, a12, a16; float f20, f24; int a28, a32, a36, a40, a44, a48, a52; unsigned char b56, b57, b58, b59; int a60, a64; float f68, f72; int a76; } S_201b08_00201B08;
extern char D_00454088[];
// MATCH func_00201B08
S_201b08_00201B08 *FUN_00201b08(S_201b08_00201B08 *s) {
s->a0 = 0;
s->a4 = 0;
s->a8 = 0;
s->a12 = 0;
s->a16 = 0;
s->a76 = (int)D_00454088;
s->f20 = 1.0f;
s->f24 = 1.0f;
s->a28 = 0;
s->a32 = 0;
s->a44 = 0;
s->a48 = 0;
s->a52 = 0;
s->b56 = 127;
s->b57 = 127;
s->b58 = 127;
s->a60 = 0;
s->a64 = 0;
s->b59 = 127;
s->f68 = 1.0f;
s->f72 = 1.0f;
return s; }

extern char D_005E8040[], D_005E7E40[], D_003C0C38[], D_0043B400_00200C10[] __asm__("D_0043B400"); extern float D_004A0390; void func_00153B40_00200C10(char *) __asm__("func_00153B40"); void func_002A2090_00200C10(char *) __asm__("func_002A2090");
// MATCH func_00200C10
void FUN_00200c10(void) { int i; char *p; func_00153B40_00200C10(D_005E8040); p = D_005E7E40; for (i = 3; i != -1; i--) { *(int *)(p + 52) = (int)D_0043B400_00200C10; *(float *)(p + 112) = 1.0f; *(int *)(p + 116) = 0; *(int *)(p + 120) = 0; *(float *)(p + 124) = D_004A0390; p += 128; } func_002A2090_00200C10(D_003C0C38); }
