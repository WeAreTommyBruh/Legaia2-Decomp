/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

extern int D_004A1A8C; extern char *D_004A1A20_00120B30 __asm__("D_004A1A20"); extern int D_00327820[]; extern int D_004A6D94;
void func_00122118(void);
// MATCH func_00120B30
void battle_00120b30(void) { int n = D_004A1A8C; int i; char *p = D_004A1A20_00120B30; for (i = 0; i < n; i++) { *(int *)(p + 4836 + i * 5472) = D_00327820[i] + 5; } D_004A6D94 = 0; func_00122118(); }

extern int D_004A1A20_1297C0 __asm__("D_004A1A20"), D_004A1AA8_1297C0 __asm__("D_004A1AA8"); extern int D_003279A0_1297C0[] __asm__("D_003279A0"); extern char D_00431628_1297C0[] __asm__("D_00431628"), D_00431638_1297C0[] __asm__("D_00431638");
void func_0021ECB0_1297C0(int, int, int) __asm__("func_0021ECB0"); void func_0021EBE8_1297C0(int, int, int, int) __asm__("func_0021EBE8"); void func_0021EE50_1297C0(int, int, int, int) __asm__("func_0021EE50"); volatile short func_001118F8_1297C0(char *, ...) __asm__("func_001118F8");
// MATCH func_001297C0
void battle_001297c0(int idx) { int o, p; o = idx * 5472; p = *(int *)(o + D_004A1A20_1297C0 + 5380); if (p != 0) { if (*(int *)(p + 44) != 0) func_0021ECB0_1297C0(D_004A1AA8_1297C0, *(int *)(p + 16), D_003279A0_1297C0[idx]); if (*(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 36) != 0) { func_001118F8_1297C0(D_00431628_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 36)); func_0021EBE8_1297C0(D_004A1AA8_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 36), o + D_004A1A20_1297C0, 0x179c00); } if (*(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 32) != 0) { func_001118F8_1297C0(D_00431628_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 32)); func_0021EBE8_1297C0(D_004A1AA8_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 32), o + D_004A1A20_1297C0, 0x1c4c00); } if (*(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 48) != 0) { func_001118F8_1297C0(D_00431638_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 48)); func_0021EE50_1297C0(D_004A1AA8_1297C0, *(int *)(*(int *)(o + D_004A1A20_1297C0 + 5380) + 48), o + D_004A1A20_1297C0, 0); } } }

extern int D_004A1A20; extern int D_004A6E24; extern int D_003279A0[]; extern char D_004317F8[];
int DbgPrintf(char *fmt, ...);
// MATCH func_0012A958
void battle_0012a958(void) { int *pp; int i, off; int e; char *c; int *q; int fl; pp = D_003279A0; i = 0; off = 0; do { e = *pp; pp = pp + 1; if (e != 0) { c = (char *)(off + D_004A1A20); if (*(int *)(*(int *)(c + 0x1444) + 0x38) < 0) *(int *)(*(int *)(c + 0x1444) + 0x38) = 0; if ((*(unsigned *)(c + 0x12d0) & 0x800) == 0) { fl = D_004A6E24; q = *(int **)(c + 0x1550); q[0x16] = 0; q[0x13] = 0; q[0x14] = 0; q[1] = 0; q[0] = 0; if (fl != 0) DbgPrintf(D_004317F8, i); } } i = i + 1; off = off + 0x1560; } while (i < 0x14); }

