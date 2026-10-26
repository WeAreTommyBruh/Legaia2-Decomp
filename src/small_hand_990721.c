/* Small functions matched by hand. */
// compiler: 990721-r5900
// cflags: -fno-thread-jumps
#include "common.h"

// MATCH func_00108C20
void FUN_00108c20(void *s)
{
    float b;
    float t;
    if (FIELD(float, s, 32) == 0.0f && FIELD(float, s, 36) == 0.0f) {
        FIELD(float, s, 0) = FIELD(float, s, 8);
        return;
    }
    b = FIELD(float, s, 36);
    t = FIELD(float, s, 20);
    FIELD(float, s, 0) = t * (FIELD(float, s, 32) * t + b) + FIELD(float, s, 4);
}

typedef struct { int w0, w4, w8; int *w12; char *vt; } O_0020B598;
extern char D_00455618[], D_00454D80[]; int func_001621F8(int, char *, int); void func_00108B80(void *);
// MATCH func_0020B598
void pchevent_0020b598(O_0020B598 *o, int fl) { int i; o->vt = D_00455618; if (o->w12 != 0) { for (i = 0; i < o->w4; i++) { if (o->w12[i] != 0) func_001621F8(o->w12[i], D_00454D80, 117); } func_001621F8((int)o->w12, D_00454D80, 118); } if (fl & 1) func_00108B80(o); }

extern int D_00343028[]; extern int D_004A3850, D_004A118C; extern char *D_004A12B0; extern char D_0042E718[], D_0042E740[]; extern int D_002F95F0[], D_002F96B0[]; void func_001118F8(char *, ...); void func_0010E820(int, int); void func_0010E938(int *, int);
// MATCH func_0010ED80
void FUN_0010ed80(int a) { int i; if (!(D_00343028[0] & 8) && D_004A3850 != 2) { if (D_004A118C & 0x40) func_001118F8(D_0042E718, D_004A12B0); if (D_004A118C & 1) func_001118F8(D_0042E740); func_0010E820(a, 103); for (i = 0; i < 32; i++) { if (i != 2) func_0010E938(D_00343028, i); } for (i = 0; i < 48; i++) { D_002F95F0[i] = -1; D_002F96B0[i] = -1; } } }

extern int D_00343028_0010EE78[] __asm__("D_00343028"); extern int D_004A3850_0010EE78 __asm__("D_004A3850"), D_004A118C_0010EE78 __asm__("D_004A118C"); extern char *D_004A12B0_0010EE78 __asm__("D_004A12B0"); extern char D_0042E750[], D_0042E778[]; extern int D_002F95F0_0010EE78[] __asm__("D_002F95F0"), D_002F96B0_0010EE78[] __asm__("D_002F96B0"); void func_001118F8(char *, ...); void func_0010E938(int *, int); void func_0010E428(int *); void func_002D38F8(void);
// MATCH func_0010EE78
void FUN_0010ee78(void) { int i; if (!(D_00343028_0010EE78[0] & 8) && D_004A3850_0010EE78 != 2) { if (D_004A118C_0010EE78 & 0x40) func_001118F8(D_0042E750, D_004A12B0_0010EE78); if (D_004A118C_0010EE78 & 1) func_001118F8(D_0042E778); for (i = 0; i < 32; i++) func_0010E938(D_00343028_0010EE78, i); for (i = 0; i < 48; i++) { D_002F95F0_0010EE78[i] = -1; D_002F96B0_0010EE78[i] = -1; } func_0010E428(D_00343028_0010EE78); func_002D38F8(); } }

extern int D_004A6DA4, D_004A1A84; void func_0012AEA8(int); int func_00121918(int);
// MATCH func_00121980
void battle_00121980(int a, int step) { func_0012AEA8(8); do { if (D_004A6DA4 < 0) D_004A6DA4 = D_004A1A84 - 1; if (D_004A6DA4 >= D_004A1A84) D_004A6DA4 = 0; if (func_00121918(D_004A6DA4)) return; D_004A6DA4 += step; } while (1); }

extern char D_0044B678[], D_0044B4A0[]; void func_00133528(int, char *, int); void func_001E2400(void *, int);
// MATCH func_001DFC78
void mizuki_001dfc78(int *o, int a) { o[25] = (int)D_0044B678; if (o[36] != 0) func_00133528(o[36], D_0044B4A0, 154); if (o[22] != 0) func_00133528(o[22], D_0044B4A0, 155); if (o[21] != 0) { if (o[57] != 0) func_00133528(o[21], D_0044B4A0, 156); } o[22] = 0; o[36] = 0; o[21] = 0; func_001E2400(o, a); }
