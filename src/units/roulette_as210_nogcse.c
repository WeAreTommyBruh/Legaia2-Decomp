/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
// cflags: -fno-gcse
#include "../common.h"


typedef struct { char p[60]; int d; char p2[8]; int a; int b; int w; } O_00170940;
extern char D_00343028_170940[] __asm__("D_00343028");
int func_0010C2B0_170940(void *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_00170940
int roulette_00170940(O_00170940 *o) { int r; if (o->d == 0) return 1; r = 0; o->a += o->d; o->b += o->d; while (o->a >= o->w << 16) o->a -= o->w << 16; while (o->b > 0x10000) { r = 1; o->b -= 0x10000; func_0010C2B0_170940(D_00343028_170940, 140, 6, 0, 0, 0, 0); } return r; }


typedef struct { char p[60]; int d; char p2[8]; int a; int b; int w; } O_00170A40;
// MATCH func_00170A40
int roulette_00170a40(O_00170A40 *o) { int r; if (o->d == 0) return 1; r = 0; o->a -= o->d; o->b += o->d; while (o->a < 0) o->a += o->w << 16; while (o->b > 0x10000) { r = 1; o->b -= 0x10000; } return r; }


extern char D_00343028_1719B0[] __asm__("D_00343028");
void rsound_0010c2b0(char *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_001719B0
int roulette_001719b0(int *p) { int r; int a, b; if (p[0] == 0) return 1; r = 0; a = p[2] + p[0]; p[3] += p[0]; p[2] = a; if (a >= 0xc0000) { int c = a; do c -= 0xc0000; while (c >= 0xc0000); p[2] = c; } b = p[3]; if (b > 0x10000) { r = 1; do { p[3] = b - 0x10000; rsound_0010c2b0(D_00343028_1719B0, 0x8c, 6, 0, 0, 0, 0); b = p[3]; } while (b > 0x10000); } return r; }


extern char D_00343028_00172040[] __asm__("D_00343028");
void rsound_0010c2b0(char *, int, int, int, int, int, int) __asm__("func_0010C2B0");
// MATCH func_00172040
int roulette_00172040(int *p) { int r; int a, b; if (p[0] == 0) return 1; r = 0; a = p[2] + p[0]; p[3] += p[0]; p[2] = a; if (a >= 0xc0000) { int c = a; do c -= 0xc0000; while (c >= 0xc0000); p[2] = c; } b = p[3]; while (b > 0x10000) { p[3] = b - 0x10000; if (r == 0) rsound_0010c2b0(D_00343028_00172040, 0xa1, 0xc, 0, 0, 0, 0); r = 1; b = p[3]; } return r; }
