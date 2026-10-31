/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { char p[1224]; void *vt; char p2[552]; int w; } O_001892E8;
extern char D_00342860[], D_0043FBA0[]; void func_00187028(void *); void func_00186F40(void *, void *, int, int);
// MATCH func_001892E8
void FUN_001892e8(O_001892E8 *o) { func_00187028(o); func_00186F40(o, D_00342860, 43, 46); if (o->w == 45) o->vt = D_0043FBA0; }

typedef struct { int x, y, z; float w; } V_00189768;
typedef struct { char p[48]; V_00189768 v; } O_00189768;
void func_0018EB98_00189768(O_00189768 *, int) __asm__("func_0018EB98"); void func_0018F3D8_00189768(O_00189768 *, int, O_00189768 *) __asm__("func_0018F3D8");
static inline void set_00189768(V_00189768 *v) { v->x = 0; v->y = 0; v->z = 0; v->w = 1.0f; }
// MATCH func_00189768
void FUN_00189768(O_00189768 *o, int b, int c) { func_0018EB98_00189768(o, c); set_00189768(&o->v); func_0018F3D8_00189768(o, b, o); }
