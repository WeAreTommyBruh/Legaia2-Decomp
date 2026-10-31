/* Functions of this report unit, matched by hand. */
// compiler: 991111-01-as210
#include "../common.h"

typedef struct { char c[8]; } V8_00164990;
typedef struct { int w0, w4, w8, w12, w16, w20, w24, w28, w32, w36; V8_00164990 v; } O_00164990;
extern V8_00164990 D_004A2CD0[];
// MATCH func_00164990
void pachislot_00164990(O_00164990 *o) { o->w32 = -1; o->w12 = 0; o->w20 = 0; o->w24 = 0; o->w8 = 0; o->v = D_004A2CD0[0]; }

typedef struct { char c[8]; } V8_001649E0;
typedef struct { char p[40]; V8_001649E0 v; } O_001649E0;
extern V8_001649E0 D_004A2CD8[];
// MATCH func_001649E0
void pachislot_001649e0(O_001649E0 *o) { o->v = D_004A2CD8[0]; }

typedef struct { char c[8]; } V8_00164AD0;
typedef struct { char p[20]; int w20; } P_00164AD0;
typedef struct { P_00164AD0 *p; char pad4[4]; short s8; short s10; int w12; int w16; int w20; int w24; char pad28[4]; int w32; char pad36[4]; V8_00164AD0 v40; } O_00164AD0;
extern V8_00164AD0 D_004A2CD0_00164AD0[3] __asm__("D_004A2CD0");
// MATCH func_00164AD0
void pachislot_00164ad0(O_00164AD0 *o) { int x; if (o->w24 >= 0) { if (o->w12 == o->s10) return; if (o->w16 != o->s10) return; if (o->w20 > 0) { o->w20--; return; } o->s8 = 0; o->w32 = -1; o->w24 = 0; o->v40 = D_004A2CD0_00164AD0[0]; return; } x = o->w16 - 1; if (x < 0) x += o->p->w20; if (o->w12 == o->s10) return; if (x != o->s10) return; if (o->w20 > 0) { o->w20--; return; } o->w32 = -1; o->s10 = (unsigned short)o->w16; o->s8 = 0; o->w24 = 0; o->v40 = D_004A2CD0_00164AD0[0]; }
