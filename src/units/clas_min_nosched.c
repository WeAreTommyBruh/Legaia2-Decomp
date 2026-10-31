/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns
#include "../common.h"

typedef struct { int a, b, c, d; } O_0029C3C8;
extern int D_004A6980, D_004A6984, D_004A6988;
// MATCH func_0029C3C8
void clas_min_0029c3c8(O_0029C3C8 *o) { o->c = 0; o->d = 1; o->a = 0; o->b = 0; D_004A6980 = 0; D_004A6984 = 0; D_004A6988 = 0; }

typedef struct { char p[516]; float a; char p2[16]; float b; char p3[16]; float c; } O_0029FF38;
// MATCH func_0029FF38
void clas_min_0029ff38(O_0029FF38 *o) { o->c = 128.0f; o->a = 128.0f; o->b = 128.0f; }

typedef struct { char pad[28]; int a28; int a32; int a36; } S_2a4990_002A4990;
extern int D_004A6598, D_004A659C;
typedef struct { int a, b, c, d; } V_2a4990_002A4990;
V_2a4990_002A4990 func_002A4570(int);
// MATCH func_002A4990
void clas_min_002a4990(S_2a4990_002A4990 *s) { V_2a4990_002A4990 t = func_002A4570(s->a28); D_004A659C = s->a36; D_004A6598 = s->a32; }
