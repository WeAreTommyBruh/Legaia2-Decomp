/* Functions of this report unit, matched by hand. */
#include "../common.h"

int func_0010B1A8(int, int, int, int, int, int);
// MATCH func_0010B188
int rsound_0010b188(int a, int b, int c, int d, int e) { return func_0010B1A8(a, b, c, d, e, -1); }

extern int D_00343028_0010BFA0[] __asm__("D_00343028"); extern int D_004A3850_0010BFA0 __asm__("D_004A3850"); extern volatile int D_004A1190;
// MATCH func_0010BFA0
int rsound_0010bfa0(void) { if (D_00343028_0010BFA0[0] & 8) return 0; if (D_004A3850_0010BFA0 == 2) return 0; return D_004A1190; }

extern char D_0042D8E8[]; extern int D_00343028_0010C570[] __asm__("D_00343028"); extern int D_004A3850_0010C570 __asm__("D_004A3850"), D_004A118C; extern char *D_004A12B0_0010C570 __asm__("D_004A12B0"); void func_001118F8_0010C570(char *, ...) __asm__("func_001118F8"); void func_002D4D98(int, int);
// MATCH func_0010C570
void rsound_0010c570(int a, int b, int c) { if (!(D_00343028_0010C570[0] & 8) && D_004A3850_0010C570 != 2) { if (D_004A118C & 0x40) func_001118F8_0010C570(D_0042D8E8, D_004A12B0_0010C570); func_002D4D98(b, c); } }

extern int D_00343028_0010C5F0[] __asm__("D_00343028"); extern int D_004A3850_0010C5F0 __asm__("D_004A3850"), D_004A118C_0010C5F0 __asm__("D_004A118C"); extern char *D_004A12B0_0010C5F0 __asm__("D_004A12B0"); extern char D_0042D908[]; void func_001118F8_0010C5F0(char *, ...) __asm__("func_001118F8"); void func_002D4CF8(int, int, int);
// MATCH func_0010C5F0
void rsound_0010c5f0(int a, unsigned i, int c, int d) { if (!(D_00343028_0010C5F0[0] & 8) && D_004A3850_0010C5F0 != 2 && i < 48) { if (D_004A118C_0010C5F0 & 0x40) func_001118F8_0010C5F0(D_0042D908, D_004A12B0_0010C5F0); func_002D4CF8(i, c, d); } }

typedef struct { char p[40]; int w40, w44; } O_0010BE68;
extern int D_00343028_0010BE68[] __asm__("D_00343028"); extern char D_0034377D[], D_00343779[]; extern int D_004A3850_0010BE68 __asm__("D_004A3850"), D_004A118C_0010BE68 __asm__("D_004A118C"), D_004A12A4_0010BE68 __asm__("D_004A12A4"); extern volatile int D_004A1190_0010BE68 __asm__("D_004A1190"); extern char *D_004A12B0_0010BE68 __asm__("D_004A12B0"); extern char D_0042D6C8[], D_0042D6F8[]; void func_001118F8_0010BE68(char *, ...) __asm__("func_001118F8"); int func_002D3A98(int); int func_002D3B28(int, int, int); void func_002D4268(int, int);
// MATCH func_0010BE68
int rsound_0010be68(O_0010BE68 *o, int a, int b, int c) { int r, ch; if ((D_00343028_0010BE68[0] & 8) || D_004A3850_0010BE68 == 2) return 0; ch = o->w40; if (ch != 0) { o->w44 = o->w44 + 1; if (o->w44 < 4) { if (D_004A118C_0010BE68 & 1) func_001118F8_0010BE68(D_0042D6C8); return -99; } o->w44 = 0; } if (D_004A118C_0010BE68 & 0x40) func_001118F8_0010BE68(D_0042D6F8, D_004A12B0_0010BE68); func_002D3A98(1); r = func_002D3B28(a, b, c); func_002D3A98(1); D_004A1190_0010BE68 = 1; o->w40 = 0; o->w44 = 0; if (D_004A12A4_0010BE68 == 11) ch = D_0034377D[0]; else ch = D_00343779[0]; if (r < 0) return r; func_002D4268(r, ch); return r; }

typedef struct { char p[1396]; int w1396, w1400, w1404, w1408; char b1412[64]; int w1476; int w1480; } O_0010CD80;
extern int D_00343028_0010CD80[] __asm__("D_00343028"); extern int D_004A3850_0010CD80 __asm__("D_004A3850"), D_004A118C_0010CD80 __asm__("D_004A118C"); extern char *D_004A12B0_0010CD80 __asm__("D_004A12B0"); extern char D_0042DD28[], D_0042DD50[]; void func_001118F8_0010CD80(char *, ...) __asm__("func_001118F8"); void func_0010E938(O_0010CD80 *, int); void func_002DD4CC_0010CD80(char *, char *) __asm__("func_002DD4CC"); void func_002DD718_0010CD80(char *) __asm__("func_002DD718"); int func_002DD5E0_0010CD80(char *) __asm__("func_002DD5E0"); int func_002DC650(char *, char *, int);
// MATCH func_0010CD80
int rsound_0010cd80(O_0010CD80 *o, int a, char *name, int c, int d) { char buf[128]; int i; char *dst, *q; if ((D_00343028_0010CD80[0] & 8) || D_004A3850_0010CD80 == 2) return 0; if (!(D_00343028_0010CD80[0] & 2)) return 0; if (o->w1396 > 0) return -5; if (name == 0) return -2; if (D_004A118C_0010CD80 & 0x40) func_001118F8_0010CD80(D_0042DD28, D_004A12B0_0010CD80); func_0010E938(o, 1); o->w1400 = a; o->w1396 = 1; o->w1404 = 0; if (d == 0) { o->w1408 = 1; o->w1480 = 0; } else { o->w1480 = d; o->w1408 = 0; } func_002DD4CC_0010CD80(buf, name); func_002DD718_0010CD80(buf); dst = o->b1412; q = dst + 63; for (i = 63; i >= 0; i--, q--) *q = 0; func_002DC650(dst, buf, func_002DD5E0_0010CD80(buf)); if (D_004A118C_0010CD80 & 1) func_001118F8_0010CD80(D_0042DD50, dst); return 1; }
