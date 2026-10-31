/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char c[8]; } V8_0016C8B0;
typedef struct { char p[32]; int a; int b; char p2[16]; V8_0016C8B0 v; } O_0016C8B0; extern V8_0016C8B0 D_004A2F68[2];
// MATCH func_0016C8B0
int FUN_0016c8b0(O_0016C8B0 *o) { int a = o->a - 6; int b = o->b - 6; o->a = a; o->b = b; if (a <= 0) { o->a = 0; o->b = 0; o->v = D_004A2F68[0]; } return 0; }

typedef struct { char c[8]; } V8_0016C6C0;
typedef struct { int a; char p0[4]; int b; char p[12]; int w24, w28; char p2[24]; V8_0016C6C0 v; } O_0016C6C0;
extern V8_0016C6C0 D_004A2F38[2];
// MATCH func_0016C6C0
int FUN_0016c6c0(O_0016C6C0 *o) { int a = o->a - 3; int b = o->b + 3; o->a = a; o->b = b; if (a <= 200) { o->a = 200; o->b = 440; o->w24 = 0; o->w28 = 0; o->v = D_004A2F38[0]; } return 0; }

typedef struct { char c[8]; } V8_0016C720;
typedef struct { char p0[8]; int w8, w12, w16, w20, w24, w28; char p1[12]; int w44; char p2[8]; V8_0016C720 v; } O_0016C720;
extern V8_0016C720 D_004A2F60[2];
// MATCH func_0016C720
int FUN_0016c720(O_0016C720 *o) { o->w24++; o->w28++; o->w16 = 8 + ((o->w24 & 0x20) >> 5); o->w20 = 14; o->w8 += 6; o->w12 -= 6; if (--o->w44 <= 0) o->v = D_004A2F60[0]; return 0; }

typedef struct { char c[8]; } V8_0016C7A0;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28; char p1[12]; int w44; char p2[8]; V8_0016C7A0 v; } O_0016C7A0;
extern V8_0016C7A0 D_004A2F60_0016C7A0[2] __asm__("D_004A2F60");
// MATCH func_0016C7A0
int FUN_0016c7a0(O_0016C7A0 *o) { o->w28++; o->w24++; o->w16 = 7; o->w20 = 15 + ((o->w28 & 0x20) >> 5); o->w0 -= 6; o->w4 -= 6; if (--o->w44 <= 0) o->v = D_004A2F60_0016C7A0[0]; return 0; }

typedef struct { char c[8]; } V8_0016C820;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28; char p1[24]; V8_0016C820 v; } O_0016C820;
extern V8_0016C820 D_004A2F68_0016C820[2] __asm__("D_004A2F68");
// MATCH func_0016C820
int FUN_0016c820(O_0016C820 *o) { o->w24++; o->w28++; o->w16 = 7; o->w20 = 14; o->w0 -= 6; o->w4 -= 6; o->w8 += 6; o->w12 -= 6; if (o->w0 < -48 || o->w4 < -24) o->v = D_004A2F68_0016C820[0]; return 0; }
