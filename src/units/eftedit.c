/* Functions of this report unit, matched by hand. */
#include "../common.h"

extern void *D_004A445C; void *func_001F7308(void *); int func_001F7318(void *); int func_001F7410(void *, int);
// MATCH func_001FDBE0
int eftedit_001fdbe0(int a, int b) { void *p = D_004A445C; while (func_001F7318(p) != a) { p = func_001F7308(p); if (p == 0) return 0; } return func_001F7410(p, b); }

extern void *D_004A445C_001FDB68 __asm__("D_004A445C"); void *func_001F7308(void *); int func_001F7318(void *); float func_001F7358(void *, int);
// MATCH func_001FDB68
float eftedit_001fdb68(int a, int b) { void *p = D_004A445C_001FDB68; while (func_001F7318(p) != a) { p = func_001F7308(p); if (p == 0) return 0.0f; } return func_001F7358(p, b); }

extern void *D_004A445C_001FDC50 __asm__("D_004A445C"); void *func_001F7308(void *); int func_001F7318(void *); void func_001F74A0(void *, int, float);
// MATCH func_001FDC50
void eftedit_001fdc50(int a, int b, float c) { void *p = D_004A445C_001FDC50; while (func_001F7318(p) != a) { p = func_001F7308(p); if (p == 0) return; } func_001F74A0(p, b, c); }

extern int D_004A4458_1FEE18 __asm__("D_004A4458");
int func_001F60B0_1FEE18(int) __asm__("func_001F60B0");
int func_001FDBE0_1FEE18(int, int) __asm__("func_001FDBE0");
void func_001FDC50_1FEE18(int, int, float) __asm__("func_001FDC50");
void func_001EA680_1FEE18(int, void *, int) __asm__("func_001EA680");
// MATCH func_001FEE18
void eftedit_001fee18(int a, int b) { float buf[128]; int i, base, k; float *p; k = func_001FDBE0_1FEE18(3, 998); base = D_004A4458_1FEE18; i = 1; k = func_001F60B0_1FEE18(k); base += k * 4; func_001EA680_1FEE18(*(int *)(base + 304), buf, b); p = buf + 1; do { func_001FDC50_1FEE18(7, i, *p); i++; p++; } while (i < 36); }
