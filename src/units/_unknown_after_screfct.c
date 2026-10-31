/* Functions of this report unit, matched by hand. */
#include "../common.h"

typedef struct { void *p; } O_00184560; int func_00180BB0(void *);
// MATCH func_00184560
int FUN_00184560(O_00184560 *o) { return o->p ? func_00180BB0(o->p) : 0; }

void func_00108B80(void);
// MATCH func_00184748
void FUN_00184748(int a, int b) { if (b & 1) func_00108B80(); }

typedef struct { char pad[24]; short adj; short p2; void (*fn)(void *, int); } VT_184518_00184518;
typedef struct { char pad[12]; VT_184518_00184518 *vt; } O_184518_00184518;
typedef struct { O_184518_00184518 *o; } S_184518_00184518;
// MATCH func_00184518
void FUN_00184518(S_184518_00184518 *s) { O_184518_00184518 *p = s->o; if (p != 0) p->vt->fn((char *)p + p->vt->adj, 3); s->o = 0; }

typedef struct { char pad[32]; short adj; short p2; int (*fn)(void *); } VT_1844d8_001844D8;
typedef struct { char pad[12]; VT_1844d8_001844D8 *vt; } O_1844d8_001844D8;
typedef struct { O_1844d8_001844D8 *o; } S_1844d8_001844D8;
// MATCH func_001844D8
int FUN_001844d8(S_1844d8_001844D8 *s) { O_1844d8_001844D8 *p = s->o; return p ? p->vt->fn((char *)p + p->vt->adj) : 0; }

extern char D_0043E460[]; void func_001118F8_00184428(char *, ...) __asm__("func_001118F8"); void func_00184518(int *); int func_00181840(unsigned, float); int func_00183BB8(void);
// MATCH func_00184428
int FUN_00184428(int *o, unsigned a, float v) { if (o[0]) { func_001118F8_00184428(D_0043E460); func_00184518(o); } if (a < 11) o[0] = func_00181840(a, v); else if (a == 100) o[0] = func_00183BB8(); return o[0] != 0; }
