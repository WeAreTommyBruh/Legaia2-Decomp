#include "../common.h"
typedef struct { float x, y, z, w; } V_29C658;
typedef struct { char p0[32]; V_29C658 v; char p1[16]; V_29C658 w; char p2[108]; short s188; } E_29C658;
typedef struct { E_29C658 *e; char p[492]; int fl; int fm; } P_29C658;
typedef struct { char p[24]; volatile int v; } C_29C658;
extern float D_00421490[]; extern int D_004A72F8;
C_29C658 *clas_min_0029c770(void); P_29C658 *clas_min_0029c6f8(int);
static inline void set_29C658(V_29C658 *v, float x, float y, float z, float w) { v->x = x; v->y = y; v->z = z; v->w = w; }
// MATCH func_0029C658
void clas_min_0029c658(void) { C_29C658 *c = clas_min_0029c770(); P_29C658 *p = clas_min_0029c6f8(-1); E_29C658 *e = p->e; set_29C658(&e->w, 0, D_00421490[4], 0, 1.0f); p->fm = D_004A72F8; p->fl = (p->fl | 1) & ~2; e->s188 = c->v; set_29C658(&e->v, D_00421490[1], D_00421490[2], D_00421490[3], 1.0f); }
