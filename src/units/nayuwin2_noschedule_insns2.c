/* Functions of this report unit, matched by hand. */
// cflags: -fno-schedule-insns2
#include "../common.h"

typedef struct { void *p; char q[28]; int v; char r[216]; char t; char u; char w; } E_1af198_001AF198;
typedef struct { char p[76]; int n; char q[280]; E_1af198_001AF198 *e; } O_1af198_001AF198;
// MATCH func_001AF198
int nayuwin2_001af198(O_1af198_001AF198 *o, int i) { E_1af198_001AF198 *e; if (i < 0 || o->n < i) return 0; e = &o->e[i]; if (e->u == 3 || e->u == 5) return e->v; if (e->u == 4) { switch (e->v) { case 0: return *(unsigned char *)e->p; case 1: return *(unsigned short *)e->p; case 2: return *(int *)e->p; case 3: return *(float *)e->p; default: return -1; } } return 0; }
