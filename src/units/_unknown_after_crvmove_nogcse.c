/* Functions of this report unit, matched by hand. */
// cflags: -fno-gcse
#include "../common.h"

typedef struct { short delta; short index; union { int (*fn)(void *, int **); short voff; } u_00163E68;
} PMF;
extern PMF D_00333A50[];
// MATCH func_00163E68
int FUN_00163e68(char *o, int **pp) { int op; int r; do { int idx; int (*fn)(void *, int **); long e; int dl; int d; op = *(*pp)++; idx = D_00333A50[op].index; if (idx > 0) { long *vt = *(long **)(o + D_00333A50[op].u_00163E68.voff); e = vt[idx - 1]; fn = (int (*)(void *, int **))(e >> 32); } else fn = D_00333A50[op].u_00163E68.fn; dl = D_00333A50[op].delta; d = idx > 0 ? (short)e + dl : dl; r = fn(o + d, pp); } while (r == 0); return op == 13; }


extern char D_004A2CA8_163A38[] __asm__("D_004A2CA8");
extern unsigned char D_0049EA61_163A38[] __asm__("D_0049EA61");
int sprintf(char *, const char *, ...) __asm__("func_002DCE40");
void func_00163780_163A38(int, int, void *) __asm__("func_00163780");
// MATCH func_00163A38
void FUN_00163a38(int x, int y, int v, int n, short *r) { char buf[64]; int i; int w, h; sprintf(buf, D_004A2CA8_163A38, n, v); h = r[3] - r[1]; h = h / 2; w = r[2] - r[0]; x += w / 2; y += h / 2; for (i = 0; i < n; i++) { int d = buf[i] - '0'; if (D_0049EA61_163A38[buf[i]] & 4) { func_00163780_163A38(x, y, r + d * 6); } x += w; } }


extern char D_004A2CB0_163C30[] __asm__("D_004A2CB0");
extern unsigned char D_0049EA61_00163C30[] __asm__("D_0049EA61");
int sprintf(char *, const char *, ...) __asm__("func_002DCE40");
void func_00163780_163C30(int, int, void *) __asm__("func_00163780");
// MATCH func_00163C30
void FUN_00163c30(int x, int y, int v, int n, short *r) { char buf[64]; int i; int w, h; sprintf(buf, D_004A2CB0_163C30, n, v); h = r[3] - r[1]; h = h / 2; w = r[2] - r[0]; x += w / 2; y += h / 2; for (i = 0; i < n; i++) { int d = buf[i] - '0'; if (D_0049EA61_00163C30[buf[i]] & 4) { func_00163780_163C30(x, y, r + d * 6); } x += w; } }
