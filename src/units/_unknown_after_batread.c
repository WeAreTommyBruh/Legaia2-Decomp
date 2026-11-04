/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern int D_003CAB30[20]; extern int D_0041EEA8[18];
// MATCH func_00220BC8
void FUN_00220bc8(void) { int i; for (i = 0; i < 18; i++) D_003CAB30[i + 1] = D_0041EEA8[i]; }

extern int D_004A4D98_2206E0 __asm__("D_004A4D98"); extern volatile int D_004A4D9C_2206E0 __asm__("D_004A4D9C"); extern int D_004A6FC0_2206E0 __asm__("D_004A6FC0"); extern char D_00457348_2206E0[] __asm__("D_00457348"), D_00457800_2206E0[] __asm__("D_00457800"), D_00457828_2206E0[] __asm__("D_00457828"), D_00343010_2206E0[] __asm__("D_00343010");
void func_00261AF8_2206E0(void) __asm__("func_00261AF8"); volatile short func_001118F8_2206E0(char *, ...) __asm__("func_001118F8"); void func_00198CB8_2206E0(char *) __asm__("func_00198CB8"); void func_00202928_2206E0(int) __asm__("func_00202928"); void func_00202878_2206E0(int, int) __asm__("func_00202878");
// MATCH func_002206E0
void FUN_002206e0(char *o, int a) { int t; if (*(int *)(o + 7004) != 0) { func_00261AF8_2206E0(); func_001118F8_2206E0(D_00457348_2206E0); func_001118F8_2206E0(D_00457800_2206E0); func_001118F8_2206E0(D_00457348_2206E0); func_00198CB8_2206E0(D_00343010_2206E0); func_00202928_2206E0(D_004A4D98_2206E0); *(int *)(o + 7004) = 0; } if (*(int *)(o + 7008) != 0 && a != 0) { func_001118F8_2206E0(D_00457828_2206E0); func_00202928_2206E0(D_004A4D9C_2206E0); if (D_004A4D98_2206E0 != 0) func_00202878_2206E0(D_004A4D98_2206E0, 3); t = D_004A4D9C_2206E0; if (t != 0) func_00202878_2206E0(t, 3); *(int *)(o + 7008) = 0; D_004A6FC0_2206E0 = 1; D_004A4D98_2206E0 = 0; D_004A4D9C_2206E0 = 0; } }

