/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[1260]; int w; } O_00226B28; typedef struct { char p[124]; float f; char p2[84]; int w; } Q_00226B28; extern float D_004A1508;
// MATCH func_00226B28
void FUN_00226b28(O_00226B28 *o, Q_00226B28 *q) { if (o->w != 0) { q->w = 0; q->f = D_004A1508; } }

// MATCH func_00223500
int FUN_00223500(char *a, int b, unsigned c) { char *e; int x; e = a + b * 8; if (c >= *(unsigned *)(e + 4)) return 0; x = *(short *)(a + 2) * c; a = (char *)*(int *)(e + 8); return (int)a + x; }

int func_00163150(int, int);
int func_00163118(int, int);
// MATCH func_00223620
int FUN_00223620(int p, int idx) { int r; int q; int k; int m; int *e; if (*(int *)(p + 4) < 100) return 0; if (*(int *)(p + 0x4d0) != 0) return 0; e = (int *)(idx * 0x38 + *(int *)(p + 0x810)); r = e[7]; if (r > 0 && (q = *(int *)(p + 0x4c)) != 0 && (m = e[12]) != 0 && (k = func_00163150(q, m)) >= 0) { r = func_00163118(q, k) - 1; } return r; }

extern int D_004A140C_2249A0 __asm__("D_004A140C"), D_004A7044_2249A0 __asm__("D_004A7044"), D_004A700C_2249A0 __asm__("D_004A700C"); extern float D_003CBB90_2249A0[] __asm__("D_003CBB90");
// MATCH func_002249A0
int FUN_002249a0(int a) { float *s; if (a == 0) return 0; if ((D_004A140C_2249A0 & 8) == 0) return 0; s = (float *)(D_004A7044_2249A0 * 0x38 + D_004A700C_2249A0); D_003CBB90_2249A0[4] = s[0]; D_003CBB90_2249A0[5] = s[1]; D_003CBB90_2249A0[6] = s[2]; D_003CBB90_2249A0[8] = s[3]; D_003CBB90_2249A0[9] = s[4]; D_003CBB90_2249A0[10] = s[5]; D_003CBB90_2249A0[20] = s[6]; return 0; }

extern int D_004A140C_2247B0 __asm__("D_004A140C"), D_004A7044_2247B0 __asm__("D_004A7044"), D_004A7084_2247B0 __asm__("D_004A7084"), D_004A7024_2247B0 __asm__("D_004A7024"); extern char D_05F79BB0_2247B0[] __asm__("D_05F79BB0"), D_06039E40_2247B0[] __asm__("D_06039E40");
void *memcpy(void *, const void *, unsigned);
void *func_00223500_2247B0(void *, int, int) __asm__("func_00223500");
// MATCH func_002247B0
int FUN_002247b0(int a) { int r; char *p; if (a == 0 || (D_004A140C_2247B0 & 8) == 0) r = 0; else { p = func_00223500_2247B0(D_05F79BB0_2247B0, D_004A7044_2247B0, D_004A7084_2247B0); memcpy(D_06039E40_2247B0, p, 96); r = 1; D_004A7024_2247B0 = 1; } return r; }

extern int D_004A140C_002248A8 __asm__("D_004A140C"), D_004A7044_002248A8 __asm__("D_004A7044"), D_004A7084_002248A8 __asm__("D_004A7084"), D_004A7024_002248A8 __asm__("D_004A7024"); extern char D_05F79BB0_002248A8[] __asm__("D_05F79BB0"), D_06039E40_002248A8[] __asm__("D_06039E40");
void *memcpy(void *, const void *, unsigned);
void *func_00223500_2248A8(void *, int, int) __asm__("func_00223500");
// MATCH func_002248A8
int FUN_002248a8(int a) { int r; char *p; if (a == 0 || (D_004A140C_002248A8 & 8) == 0) r = 0; else { p = func_00223500_2248A8(D_05F79BB0_002248A8, D_004A7044_002248A8, D_004A7084_002248A8); memcpy(p, D_06039E40_002248A8, 96); r = 1; D_004A7024_002248A8 = 1; } return r; }
