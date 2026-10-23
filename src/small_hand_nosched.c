/* Small functions matched by hand. */
// cflags: -fno-schedule-insns
#include "common.h"

typedef struct { char pad[32]; int a[4]; } O_0015EBE8;
// MATCH func_0015EBE8
void flare_0015ebe8(O_0015EBE8 *o, int a, int b, int c) { int *q; o->a[0] = a; q = o->a; q[3] = 128; q[1] = b; q[2] = c; }

typedef struct { char p[68]; float f; char p2[8]; int n; } O_001E2588;
// MATCH func_001E2588
int akari_001e2588(O_001E2588 *o) { return (int)o->f >= o->n; }

// MATCH func_0022D080
float FUN_0022d080(float a, float b, float c) { return __builtin_fabsf(a - b) / __builtin_fabsf(b - c); }

typedef struct { char p[56]; unsigned char a, b, c, d; char p2[8]; float f1; float f2; } O_00201CE0;
// MATCH func_00201CE0
void sprite_00201ce0(O_00201CE0 *o) { o->d = 127; o->f2 = 1.0f; o->a = 127; o->b = 127; o->c = 127; o->f1 = 1.0f; }

typedef struct { int a, b, c, d, e; } O_001948A0;
// MATCH func_001948A0
void FUN_001948a0(O_001948A0 *o, int a, char *p, int n) { o->d = 0; o->a = a; o->c = 0; o->b = (int)p; o->e = n; if (n > 0) { do { *(int *)p = 0; p += 0x4ce40; } while (--n != 0); } }

typedef struct { int a, b, c, d; } O_0029C3C8;
extern int D_004A6980, D_004A6984, D_004A6988;
// MATCH func_0029C3C8
void clas_min_0029c3c8(O_0029C3C8 *o) { o->c = 0; o->d = 1; o->a = 0; o->b = 0; D_004A6980 = 0; D_004A6984 = 0; D_004A6988 = 0; }

typedef struct { char p[516]; float a; char p2[16]; float b; char p3[16]; float c; } O_0029FF38;
// MATCH func_0029FF38
void clas_min_0029ff38(O_0029FF38 *o) { o->c = 128.0f; o->a = 128.0f; o->b = 128.0f; }

typedef struct { char p[112]; int a; long long b; } P_002C2DE8;
typedef struct { char p[64]; P_002C2DE8 *q; } O_002C2DE8;
// MATCH func_002C2DE8
void FUN_002c2de8(O_002C2DE8 *o) { P_002C2DE8 *p = o->q; p->b = 0; p->a = 0; }

typedef struct { char p[148]; int a, b, c; } P_002C2C30;
typedef struct { char p[64]; P_002C2C30 *q; } O_002C2C30;
// MATCH func_002C2C30
void FUN_002c2c30(O_002C2C30 *o, int a, int b, int c) { P_002C2C30 *p = o->q; p->c = c; p->a = a; p->b = b; }

typedef struct { int a, b, c, d, e; } O_002C3720;
// MATCH func_002C3720
int FUN_002c3720(O_002C3720 *o, int x, int y) { o->d = x >> 4; o->e = y >> 4; o->b = x; o->c = y; return 1; }

typedef struct { int a, b, c, d; } N_002DA520;
extern char D_0049E7B0_002DA520[] __asm__("D_0049E7B0");
// MATCH func_002DA520
void FUN_002da520(N_002DA520 *n, int a, int b, int c) { if (n != 0) { n->d = c; n->a = a; n->b = (int)D_0049E7B0_002DA520; n->c = b; } }

typedef struct { int a, b, c, d; } N_002DB0E0;
extern char D_0049E998[];
// MATCH func_002DB0E0
void FUN_002db0e0(N_002DB0E0 *n, int a, int b, int c) { if (n != 0) { n->d = b; n->a = a; n->b = (int)D_0049E998; n->c = c; } }
