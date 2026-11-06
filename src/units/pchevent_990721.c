/* Functions of this report unit, matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "../common.h"

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B598;
extern char D_00455618[], D_00454D80[]; int func_001621F8(int, char *, int); void func_00108B80(void *);
// MATCH func_0020B598
void pchevent_0020b598(O_0020B598 *o, int fl) { int i; o->vt = D_00455618; if (o->w12 != 0) { for (i = 0; i < o->w4; i++) { if (o->w12[i] != 0) func_001621F8(o->w12[i], D_00454D80, 117); } func_001621F8((int)o->w12, D_00454D80, 118); } if (fl & 1) func_00108B80(o); }

extern int D_004A45E8_20DBB8 __asm__("D_004A45E8"), D_004A1444_20DBB8 __asm__("D_004A1444"), D_004A140C_0020DBB8 __asm__("D_004A140C"), D_004A46C8_20DBB8 __asm__("D_004A46C8"), D_004A1430_20DBB8 __asm__("D_004A1430"), D_004A1434_20DBB8 __asm__("D_004A1434"); extern char D_00455098_20DBB8[] __asm__("D_00455098"), D_00455088_20DBB8[] __asm__("D_00455088");
void *func_0020BBD8_20DBB8(int) __asm__("func_0020BBD8"); void func_0029F868_20DBB8(int, int, int) __asm__("func_0029F868"); int func_00213258_20DBB8(int, int, int) __asm__("func_00213258"); void func_00239568_20DBB8(char *, int, int, int, int, ...) __asm__("func_00239568");
// MATCH func_0020DBB8
void pchevent_0020dbb8(int p) { int *q; int v, m, x; q = func_0020BBD8_20DBB8(D_004A45E8_20DBB8); if (q == 0) return; if (p != 0 && D_004A1444_20DBB8 == 0 && (D_004A140C_0020DBB8 & 0xc) != 0 && q[119] != 0) func_0029F868_20DBB8(q[119], q[0], D_004A46C8_20DBB8); v = 0xa0a0a0; if (p != 0 && D_004A1444_20DBB8 == 0) v = 0xc0c0; m = *(int *)(q[0] + 152); if (m != 0) { x = D_004A1430_20DBB8 + 6; func_00239568_20DBB8(D_00455088_20DBB8, x, D_004A1434_20DBB8, v, D_004A46C8_20DBB8, func_00213258_20DBB8(m, *(short *)(q[0] + 188), D_004A46C8_20DBB8)); return; } func_00239568_20DBB8(D_00455098_20DBB8, D_004A1430_20DBB8 + 6, D_004A1434_20DBB8, v, D_004A46C8_20DBB8); }

extern int D_004A45E8_0020DCD8 __asm__("D_004A45E8"), D_004A1444_0020DCD8 __asm__("D_004A1444"), D_004A140C_0020DCD8 __asm__("D_004A140C"), D_004A46CC_20DCD8 __asm__("D_004A46CC"), D_004A1430_0020DCD8 __asm__("D_004A1430"), D_004A1434_0020DCD8 __asm__("D_004A1434"); extern char D_00455098_0020DCD8[] __asm__("D_00455098"), D_00455088_0020DCD8[] __asm__("D_00455088");
void *func_0020BBD8_20DCD8(int) __asm__("func_0020BBD8"); void func_0029F8D8_20DCD8(int, int, int) __asm__("func_0029F8D8"); int func_00213258_20DCD8(int, int, int) __asm__("func_00213258"); void func_00239568_20DCD8(char *, int, int, int, int, ...) __asm__("func_00239568");
// MATCH func_0020DCD8
void pchevent_0020dcd8(int p) { int *q; int v, m, x; q = func_0020BBD8_20DCD8(D_004A45E8_0020DCD8); if (q == 0) return; if (p != 0 && D_004A1444_0020DCD8 == 0 && (D_004A140C_0020DCD8 & 0xc) != 0 && q[119] != 0) func_0029F8D8_20DCD8(q[119], q[0], D_004A46CC_20DCD8); v = 0xa0a0a0; if (p != 0 && D_004A1444_0020DCD8 == 0) v = 0xc0c0; m = *(int *)(q[0] + 152); if (m != 0) { x = D_004A1430_0020DCD8 + 6; func_00239568_20DCD8(D_00455088_0020DCD8, x, D_004A1434_0020DCD8, v, D_004A46CC_20DCD8, func_00213258_20DCD8(m, *(short *)(q[0] + 188), D_004A46CC_20DCD8)); return; } func_00239568_20DCD8(D_00455098_0020DCD8, D_004A1430_0020DCD8 + 6, D_004A1434_0020DCD8, v, D_004A46CC_20DCD8); }

